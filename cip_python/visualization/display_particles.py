import vtk
import math
import numpy as np
from optparse import OptionParser
from vtk.util.numpy_support import vtk_to_numpy



class DisplayParticles:
    def __init__(self, file_list,spacing_list,feature_type,irad = 1.2, h_th=-200,
                 glyph_type='sphere', glyph_scale_factor=1,use_field_data=True, opacity_list=[],
                 color_list=[], lung=[]):
      
        assert feature_type == "ridge_line" or feature_type == "valley_line" \
        or feature_type == "ridge_surface" or feature_type == "valley_surface" \
        or feature_type == "vessel" or feature_type == "airway" \
        or feature_type == "fissure", "Invalid feature type"
      
        if feature_type == "airway":
          feature_type = "valley_line"
        elif feature_type == "vessel":
          feature_type = "ridge_line"
        elif feature_type == "fissure":
          feature_type = "ridge_surface"
      
        self.mapper_list = list()
        self.actor_list = list()
        self.glyph_list = list()
        self.glyph_type = glyph_type
        self.file_list = file_list
        self.spacing_list = spacing_list
        self.opacity_list = opacity_list
        self.irad = irad
        self.h_th = h_th
        self.color_list = color_list
        self.lung = lung
        self.use_field_data = use_field_data
        self.feature_type = feature_type
        self.normal_map=dict()
        self.normal_map['ridge_line'] = "hevec0"
        self.normal_map['valley_line'] = "hevec2"
        self.normal_map['ridge_surface'] = "hevec2"
        self.normal_map['valley_surface'] = "hevec0"
        self.strength_map=dict()
        self.strength_map['ridge_line'] = "h1"
        self.strength_map['valley_line'] = "h1"
        self.strength_map['ridge_surface'] = "h2"
        self.strength_map['valley_surface'] = "h0"
  
        if feature_type == 'ridge_line' or feature_type == 'valley_line':
            self.height = irad
            self.radius = 0.5
        elif feature_type == 'ridge_surface' or feature_type == 'valley_surface':
            self.height = 0.5
            self.radius = irad
  
        self.min_rad = 0.5
        self.max_rad = 6
        self.glyph_scale_factor = glyph_scale_factor

        self.capture_prefix = ""
        self.capture_count = 1

        # VTK Objects
        self.ren = vtk.vtkRenderer()
        self.renWin = vtk.vtkRenderWindow()
        self.iren = vtk.vtkRenderWindowInteractor()
  
        self.image_count = 1


    def compute_radius (self,poly,spacing):
        if self.use_field_data == False:
            scale = poly.GetPointData().GetArray("scale")
            strength = poly.GetPointData().GetArray(self.strength_map[self.feature_type])
            val = poly.GetPointData().GetArray('val')
        else:
            scale=poly.GetFieldData().GetArray("scale")
            strength = poly.GetFieldData().GetArray(self.strength_map[self.feature_type])
            val = poly.GetFieldData().GetArray('val')

        np = poly.GetNumberOfPoints()
        print np
        radiusA=vtk.vtkDoubleArray()
        radiusA.SetNumberOfTuples(np)
        si=0.2
              
        arr = vtk_to_numpy(strength)
        print arr[0]
        for kk in range(np):
            ss=float(scale.GetValue(kk))
          
            #rad=math.sqrt(2.0) * ( math.sqrt(spacing**2.0 (ss**2.0 + si**2.0)) - 1.0*spacing*s0 )
            rad=math.sqrt(2)*spacing*ss
            if self.feature_type == 'ridge_line':
              test= arr[kk] > self.h_th
            elif self.feature_type == 'valley_line':
              test= arr[kk] < self.h_th
            elif self.feature_type == 'ridge_surface':
              test= arr[kk] > self.h_th
            elif self.feature_type == 'valley_surface':
              test= arr[kk] < self.h_th

            if test==True:
                rad=0
            if rad < spacing/2:
                rad=0
            radiusA.SetValue(kk,rad)

        poly.GetPointData().SetScalars(radiusA)
        return poly

    def create_glyphs (self, poly):    
        if self.glyph_type == 'sphere':
            glyph = vtk.vtkSphereSource()
            glyph.SetRadius(1)
            glyph.SetPhiResolution(8)
            glyph.SetThetaResolution(8)
        elif self.glyph_type == 'cylinder':
            glyph = vtk.vtkCylinderSource()
            glyph.SetHeight(self.height)
            glyph.SetRadius(self.radius)
            glyph.SetCenter(0,0,0)
            glyph.SetResolution(10)
            glyph.CappingOn()

        tt = vtk.vtkTransform()
        tt.RotateZ(90)
        tf = vtk.vtkTransformPolyDataFilter()
        tf.SetInput(glyph.GetOutput())
        tf.SetTransform(tt)
        tf.Update()

        glypher = vtk.vtkGlyph3D()
        glypher.SetInput(poly)
        glypher.SetSource(tf.GetOutput())
        glypher.SetVectorModeToUseNormal()
        glypher.SetScaleModeToScaleByScalar()
        glypher.SetScaleFactor(self.glyph_scale_factor)
        glypher.Update()

        return glypher

    def create_actor (self, glyph , opacity=1,color=[0.1,0.1,0.1]):
        mapper=vtk.vtkPolyDataMapper()
        mapper.SetInput(glyph.GetOutput())
        mapper.SetColorModeToMapScalars()
        mapper.SetScalarRange(self.min_rad,self.max_rad)
        if len(color) > 0:
            mapper.ScalarVisibilityOff()
        #mapper.SetScalarRange(self.min_rad,self.max_rad)
            #else:
        #    mapper.SetColorModeToDefault()
        print color 
        actor = vtk.vtkActor()
        actor.SetMapper(mapper)
        if len(color) > 0 :
            actor.GetProperty().SetColor(color)
        actor.GetProperty().SetOpacity(opacity)
        self.mapper_list.append(mapper)
        self.actor_list.append(actor)
        for aa in self.actor_list:
            self.ren.AddActor(aa)
            self.ren.SetBackground(1,1,1)
        return actor

    def add_color_bar(self):
        colorbar=vtk.vtkScalarBarActor()
        colorbar.SetMaximumNumberOfColors(400)
        colorbar.SetLookupTable(self.mapper_list[0].GetLookupTable())
        colorbar.SetWidth(0.09)
        colorbar.SetPosition(0.91,0.1)
        colorbar.SetLabelFormat("%.3g mm")
        colorbar.VisibilityOn()
        
        if len(self.color_list) == 0:
            self.ren.AddActor(colorbar)

    def render(self,widht=800,height=800):
        # create a rendering window and renderer
        self.renWin.AddRenderer(self.ren)
        self.renWin.SetSize(widht,height)
        self.renWin.SetAAFrames(0)

        # create a renderwindowinteractor
        self.iren.SetRenderWindow(self.renWin)

        # enable user interface interactor
        # Set observer
        self.iren.AddObserver('KeyPressEvent', self.capture_window, -1.0)

        self.iren.Initialize()
        self.renWin.Render()
        self.iren.Start()
                                
    def execute(self):
        for kk,file_name in enumerate(self.file_list):
            reader=vtk.vtkPolyDataReader()
            reader.SetFileName(file_name)
            reader.Update()
            
            poly = self.compute_radius(reader.GetOutput(),spacing_list[kk])
            if self.use_field_data == False:
                poly.GetPointData().\
                    SetNormals(poly.GetPointData().\
                               GetArray(self.normal_map[self.feature_type]))
            else:
                poly.GetPointData().\
                    SetNormals(poly.GetFieldData().\
                               GetArray(self.normal_map[self.feature_type]))
        
            glypher=self.create_glyphs(poly)
            if len(self.color_list) <= kk:
                color=[]
            else:
                color=self.color_list[kk]
            if len(self.opacity_list) <= kk:
                opacity=1
            else:
                opacity=self.opacity_list[kk]
            self.create_actor(glypher,color=color,opacity=opacity)
        
        if len(self.lung)>0:
            reader=vtk.vtkPolyDataReader()
            reader.SetFileName(self.lung)
            reader.Update()
            tt=vtk.vtkTransform()
            tt.Identity()
            tt.GetMatrix().SetElement(0,0,-1)
            tt.GetMatrix().SetElement(1,1,-1)
            tf=vtk.vtkTransformPolyDataFilter()
            tf.SetTransform(tt)
            tf.SetInput(reader.GetOutput())
            tf.SetTransform(tt)
            self.create_actor(tf,0.1,color=[0.8,0.4,0.01])

        self.add_color_bar()
        self.render()
        
    def capture_window(self,obj, event):
      if self.capture_prefix == "":
        return
      key = obj.GetKeySym()
      print "Key press "+key
      if key == "s":
        ff = vtk.vtkWindowToImageFilter()
        sf = vtk.vtkPNGWriter()
        
        ff.SetInput(self.renWin)
        ff.SetMagnification(4)
        sf.SetInput(ff.GetOutput())
        sf.SetFileName(self.capture_prefix+ "%03d.png" % self.capture_count )
        self.renWin.Render()
        ff.Modified()
        sf.Write()
        self.capture_count = 1+self.capture_count


if __name__ == "__main__":
    parser = OptionParser()
    parser.add_option("-i", help='TODO', dest="file_name")
    parser.add_option("-s", help='TODO', dest="spacing")
    parser.add_option("--feature", help='TODO', dest="feature_type", \
                      default="vessel")
    parser.add_option("--irad", help='interparticle distance', dest="irad", \
                      default=1.2)
    parser.add_option("--hth", help='TODO', dest="hth", default=0)
    parser.add_option("--color", help='TODO', dest="color_list", default="")
    parser.add_option("--opacity", help='TODO', dest="opacity_list", \
                      default="")
    parser.add_option("-l", help='TODO', dest="lung_filename", default="")
    parser.add_option("--useFieldData", help='TODO', dest="use_field_data", \
                      action="store_true", default=False)
  
    parser.add_option("--glpyhScale", help='TODO', dest="glyph_scale_factor", \
                        default=1)
  
    parser.add_option("--capturePrefix", help='Prefix filename to save screenshots. This options enables screen capture. Press the "s" key to capture a screenshot.', \
                      dest="capture_prefix", default="")

    (options, args) = parser.parse_args()

    translate_color = dict()
    translate_color['red'] = [1, 0.1, 0.1]
    translate_color['green'] = [0.1, 0.8, 0.1]
    translate_color['orange'] = [0.95, 0.5, 0.01]
    translate_color['blue'] = [0.1, 0.1, 0.9]

    file_list = [i for i in str.split(options.file_name,',')]
    use_field_data = options.use_field_data
    spacing_list = [float(i) for i in str.split(options.spacing,',')]
    lung_filename = options.lung_filename

    if options.opacity_list == "":
        opacity_list=[]
    else:
        opacity_list = [float(i) for i in str.split(options.opacity_list,',')]
                           
    if options.color_list == "" :
        color_list=[]
    else:
        color_list = [translate_color[val] for val in str.split(options.color_list,',')]

    print color_list

    print use_field_data

    dv = DisplayParticles(file_list, spacing_list,options.feature_type,float(options.irad),float(options.hth), \
        'cylinder', float(options.glyph_scale_factor),use_field_data, opacity_list, color_list, lung_filename)
    dv.capture_prefix = options.capture_prefix
    dv.execute()
