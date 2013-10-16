// This file was automatically generated by:
//  /Users/jross/Downloads/Slicer4/Slicer4-SuperBuild-Release/SlicerExecutionModel-build/GenerateCLP/bin/GenerateCLP --InputXML /Users/jross/Downloads/ChestImagingPlatformPrivate/CommandLineTools/RegisterLabelMaps/RegisterLabelMaps.xml --OutputCxx /Users/jross/Downloads/ChestImagingPlatformPrivate/CommandLineTools/RegisterLabelMaps/RegisterLabelMapsCLP.h
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <sstream>

#include "tclap/CmdLine.h"
#include "ModuleProcessInformation.h"

#ifdef WIN32
#define Module_EXPORT __declspec(dllexport)
#else
#define Module_EXPORT 
#endif

#if defined(main) && !defined(REGISTER_TEST)
// If main defined as a preprocessor symbol, redefine it to the expected entry point.
#undef main
#define main ModuleEntryPoint

extern "C" {
  Module_EXPORT char *GetXMLModuleDescription();
  Module_EXPORT int ModuleEntryPoint(int, char*[]);
}
#endif

extern "C" {
Module_EXPORT char XMLModuleDescription[] = 
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
"<executable>\n"
"  <category>Examples</category>\n"
"  <title>ResampleLabelMaps</title>\n"
"  <description><![CDATA[This program Registers an input label map to a target label map. It takes as input the 2 label maps and generates either a transform file or outputs the values of the transformation matrix and header information to a file.]]></description>\n"
"  <version>0.0.1</version>\n"
"  <documentation-url>http://www.slicer.org/slicerWiki/index.php/Documentation/4.2/Modules/ResampleLabelMap</documentation-url>\n"
"  <license>Slicer</license>\n"
"  <contributor> Applied Chest Imaging Laboratory, Brigham and women's hospital</contributor>\n"
"  <acknowledgements>This work was partially funded ...</acknowledgements>\n"
"  <parameters>\n"
"    <string>\n"
"      <name>fixedImageFileName</name>\n"
"      <label>fixed Image FileName</label>\n"
"      <channel>input</channel>\n"
"      <flag>f</flag>\n"
"      <longflag>--fixedImageFileName</longflag>\n"
"      <description><![CDATA[fixed Image File Name]]></description>\n"
"      <default>q</default>\n"
"    </string>   \n"
"    <string>\n"
"      <name>movingImageFileName</name>\n"
"      <label>moving Image FileName</label>\n"
"      <channel>input</channel>\n"
"      <flag>m</flag>\n"
"      <longflag>--movingImageFileName</longflag>\n"
"      <description><![CDATA[moving Image FileName]]></description>\n"
"      <default>q</default>\n"
"    </string>   \n"
"    <string>\n"
"      <name>movingImageID</name>\n"
"      <label>moving Image subject ID</label>\n"
"      <channel>input</channel>\n"
"      <flag>s</flag>\n"
"      <longflag>--movingImageID</longflag>\n"
"      <description><![CDATA[Moving Image subject ID. If not specified, the subject ID will be automatically extracted from the file path]]></description>\n"
"      <default>q</default>\n"
"    </string>   \n"
"    <string>\n"
"      <name>fixedImageID</name>\n"
"      <label>Fixed Image subject ID</label>\n"
"      <channel>input</channel>\n"
"      <flag>u</flag>\n"
"      <longflag>--fixedImageID</longflag>\n"
"      <description><![CDATA[Fixed Image subject ID. If not specified, the subject ID will be automatically extracted from the file path]]></description>\n"
"      <default>q</default>\n"
"    </string> \n"
"    <string>\n"
"      <name>registrationID</name>\n"
"      <label>registration ID ID</label>\n"
"      <channel>input</channel>\n"
"      <flag>v</flag>\n"
"      <longflag>--registrationID</longflag>\n"
"      <default>NA</default>\n"
"      <description><![CDATA[unique Id for the registration process.]]></description>\n"
"    </string> \n"
"\n"
"    <float>\n"
"      <name>downsampleFactor</name>\n"
"      <label>downsample Factor</label>\n"
"      <channel>input</channel>\n"
"      <flag>d</flag>\n"
"      <longflag>--degrees</longflag>\n"
"      <description><![CDATA[downsampleFactor]]></description>\n"
"      <default>1.0</default>\n"
"    </float>  \n"
"    <float>\n"
"      <name>maxStepLength</name>\n"
"      <label>max Step Length</label>\n"
"      <channel>input</channel>\n"
"      <flag>x</flag>\n"
"      <longflag>--max</longflag>\n"
"      <description><![CDATA[maxStepLength]]></description>\n"
"      <default>1.0</default>\n"
"    </float>  \n"
"    <float>\n"
"      <name>minStepLength</name>\n"
"      <label>min Step Length</label>\n"
"      <channel>input</channel>\n"
"      <flag>y</flag>\n"
"      <longflag>--min</longflag>\n"
"      <description><![CDATA[minStepLength]]></description>\n"
"      <default>0.001</default>\n"
"    </float> \n"
"    <integer>\n"
"      <name>numberOfIterations</name>\n"
"      <label>number Of Iterations</label>\n"
"      <channel>input</channel>\n"
"      <flag>n</flag>\n"
"      <longflag>--numberOfIterations</longflag>\n"
"      <description><![CDATA[Number of iterations. ]]></description>\n"
"      <default>20</default>\n"
"    </integer>   \n"
"    <float>\n"
"      <name>translationScale</name>\n"
"      <label>translation Scale</label>\n"
"      <channel>input</channel>\n"
"      <flag>t</flag>\n"
"      <longflag>--translationScale</longflag>\n"
"      <description><![CDATA[translationScale]]></description>\n"
"      <default>0.001</default>\n"
"    </float> \n"
"    <string>\n"
"      <name>outputImageFileName</name>\n"
"      <label>output Image FileName</label>\n"
"      <channel>output</channel>\n"
"      <flag>z</flag>\n"
"      <longflag>--outputImage</longflag>\n"
"      <description><![CDATA[Output image file name]]></description>\n"
"      <default>q</default>\n"
"    </string>  \n"
"\n"
"    <string>\n"
"      <name>outputTransformFileName</name>\n"
"      <label>output Transform FileName</label>\n"
"      <channel>output</channel>\n"
"      <flag>q</flag>\n"
"      <longflag>--outputTransform</longflag>\n"
"      <description><![CDATA[Output transform file name]]></description>\n"
"      <default>q</default>\n"
"    </string>   \n"
"\n"
"<integer-vector>\n"
"      <name>regionVecArg</name>\n"
"      <longflag>regionVec</longflag>\n"
"      <flag>r</flag>\n"
"      <label>regionVec</label>\n"
"      <description><![CDATA[Specify a region in a region-type pair you want to crop. This flag should be used together with the -typePair flag]]></description>\n"
"</integer-vector>\n"
"\n"
"<integer-vector>\n"
"      <name>typeVecArg</name>\n"
"      <longflag>typeVec</longflag>\n"
"      <flag>c</flag>\n"
"      <label>typeVec</label>\n"
"      <description><![CDATA[Specify a region in a region-type pair you want to crop. This flag should be used together with the -typePair flag]]></description>\n"
"</integer-vector>\n"
"\n"
"<integer-vector>\n"
"      <name>typePairVecArg</name>\n"
"      <longflag>typePairVec</longflag>\n"
"      <flag>a</flag>\n"
"      <label>typePairVec</label>\n"
"      <description><![CDATA[Specify a type in a region type pair you want to crop. This flag should be used together with the egionPair flag]]></description>\n"
"</integer-vector>\n"
"\n"
"<integer-vector>\n"
"      <name>regionPairVecArg</name>\n"
"      <longflag>regionPairVec</longflag>\n"
"      <flag>b</flag>\n"
"      <label>regionPairVec</label>\n"
"      <description><![CDATA[Specify a region in a region type pair you want to crop. This flag should be used together with the -typePair flag]]></description>\n"
"</integer-vector>\n"
"\n"
"  </parameters>\n"
"</executable>\n"
"\n"
;

}

void
splitString (const std::string &text,
             const std::string &separators,
             std::vector<std::string> &words)
{
  const std::string::size_type n = text.length();
  std::string::size_type start = text.find_first_not_of(separators);
  while (start < n)
    {
    std::string::size_type stop = text.find_first_of(separators, start);
    if (stop > n) stop = n;
    words.push_back(text.substr(start, stop - start));
    start = text.find_first_not_of(separators, stop+1);
    }
}

void
splitFilenames (const std::string &text,
                std::vector<std::string> &words)
{
  const std::string::size_type n = text.length();
  bool quoted;
  std::string comma(",");
  std::string quote("\"");
  std::string::size_type start = text.find_first_not_of(comma);
  while (start < n)
    {
    quoted = false;
    std::string::size_type startq = text.find_first_of(quote, start);
    std::string::size_type stopq = text.find_first_of(quote, startq+1);
    std::string::size_type stop = text.find_first_of(comma, start);
    if (stop > n) stop = n;
    if (startq != std::string::npos && stopq != std::string::npos)
      {
      while (startq < stop && stop < stopq && stop != n)
         {
         quoted = true;
         stop = text.find_first_of(comma, stop+1);
         if (stop > n) stop = n;
         }
      }
    if (!quoted)
      {
      words.push_back(text.substr(start, stop - start));
      }
    else
      {
      words.push_back(text.substr(start+1, stop - start-2));
      }
    start = text.find_first_not_of(comma, stop+1);
    }
}

char *GetXMLModuleDescription()
{
   return XMLModuleDescription;
}

#define GENERATE_LOGO
#define GENERATE_XML \
  if (argc >= 2 && (strcmp(argv[1],"--xml") == 0)) \
    { \
    std::cout << GetXMLModuleDescription(); \
    return EXIT_SUCCESS; \
    }
#define GENERATE_TCLAP \
    std::string fixedImageFileName = "q"; \
    std::string movingImageFileName = "q"; \
    std::string movingImageID = "q"; \
    std::string fixedImageID = "q"; \
    std::string registrationID = "NA"; \
    float downsampleFactor = 1.0; \
    float maxStepLength = 1.0; \
    float minStepLength = 0.001; \
    int numberOfIterations = 20; \
    float translationScale = 0.001; \
    std::string outputImageFileName = "q"; \
    std::string outputTransformFileName = "q"; \
    std::string regionVecArgTemp; \
    std::vector<int> regionVecArg; \
    std::string typeVecArgTemp; \
    std::vector<int> typeVecArg; \
    std::string typePairVecArgTemp; \
    std::vector<int> typePairVecArg; \
    std::string regionPairVecArgTemp; \
    std::vector<int> regionPairVecArg; \
    bool echoSwitch = false; \
    bool xmlSwitch = false; \
    std::string processInformationAddressString = "0"; \
    std::string returnParameterFile; \
    std::string fullDescription("Description: "); \
    fullDescription += "This program Registers an input label map to a target label map. It takes as input the 2 label maps and generates either a transform file or outputs the values of the transformation matrix and header information to a file."; \
    if (!std::string("Applied Chest Imaging Laboratory, Brigham and women's hospital").empty()) \
      { \
      fullDescription += "\nAuthor(s): Applied Chest Imaging Laboratory, Brigham and women's hospital"; \
      } \
    if (!std::string("This work was partially funded ...").empty()) \
      { \
      fullDescription += "\nAcknowledgements: This work was partially funded ..."; \
      } \
    TCLAP::CmdLine commandLine (fullDescription, \
       ' ', \
      "0.0.1" ); \
 \
      std::ostringstream msg; \
    msg.str("");msg << "fixed Image File Name (default: " << fixedImageFileName << ")"; \
    TCLAP::ValueArg<std::string > fixedImageFileNameArg("f", "fixedImageFileName", msg.str(), 0, fixedImageFileName, "std::string", commandLine); \
 \
    msg.str("");msg << "moving Image FileName (default: " << movingImageFileName << ")"; \
    TCLAP::ValueArg<std::string > movingImageFileNameArg("m", "movingImageFileName", msg.str(), 0, movingImageFileName, "std::string", commandLine); \
 \
    msg.str("");msg << "Moving Image subject ID. If not specified, the subject ID will be automatically extracted from the file path (default: " << movingImageID << ")"; \
    TCLAP::ValueArg<std::string > movingImageIDArg("s", "movingImageID", msg.str(), 0, movingImageID, "std::string", commandLine); \
 \
    msg.str("");msg << "Fixed Image subject ID. If not specified, the subject ID will be automatically extracted from the file path (default: " << fixedImageID << ")"; \
    TCLAP::ValueArg<std::string > fixedImageIDArg("u", "fixedImageID", msg.str(), 0, fixedImageID, "std::string", commandLine); \
 \
    msg.str("");msg << "unique Id for the registration process. (default: " << registrationID << ")"; \
    TCLAP::ValueArg<std::string > registrationIDArg("v", "registrationID", msg.str(), 0, registrationID, "std::string", commandLine); \
 \
    msg.str("");msg << "downsampleFactor (default: " << downsampleFactor << ")"; \
    TCLAP::ValueArg<float > downsampleFactorArg("d", "degrees", msg.str(), 0, downsampleFactor, "float", commandLine); \
 \
    msg.str("");msg << "maxStepLength (default: " << maxStepLength << ")"; \
    TCLAP::ValueArg<float > maxStepLengthArg("x", "max", msg.str(), 0, maxStepLength, "float", commandLine); \
 \
    msg.str("");msg << "minStepLength (default: " << minStepLength << ")"; \
    TCLAP::ValueArg<float > minStepLengthArg("y", "min", msg.str(), 0, minStepLength, "float", commandLine); \
 \
    msg.str("");msg << "Number of iterations. (default: " << numberOfIterations << ")"; \
    TCLAP::ValueArg<int > numberOfIterationsArg("n", "numberOfIterations", msg.str(), 0, numberOfIterations, "int", commandLine); \
 \
    msg.str("");msg << "translationScale (default: " << translationScale << ")"; \
    TCLAP::ValueArg<float > translationScaleArg("t", "translationScale", msg.str(), 0, translationScale, "float", commandLine); \
 \
    msg.str("");msg << "Output image file name (default: " << outputImageFileName << ")"; \
    TCLAP::ValueArg<std::string > outputImageFileNameArg("z", "outputImage", msg.str(), 0, outputImageFileName, "std::string", commandLine); \
 \
    msg.str("");msg << "Output transform file name (default: " << outputTransformFileName << ")"; \
    TCLAP::ValueArg<std::string > outputTransformFileNameArg("q", "outputTransform", msg.str(), 0, outputTransformFileName, "std::string", commandLine); \
 \
    msg.str("");msg << "Specify a region in a region-type pair you want to crop. This flag should be used together with the -typePair flag";    TCLAP::ValueArg<std::string > regionVecArgArg("r", "regionVec", msg.str(), 0, regionVecArgTemp, "std::vector<int>", commandLine); \
 \
    msg.str("");msg << "Specify a region in a region-type pair you want to crop. This flag should be used together with the -typePair flag";    TCLAP::ValueArg<std::string > typeVecArgArg("c", "typeVec", msg.str(), 0, typeVecArgTemp, "std::vector<int>", commandLine); \
 \
    msg.str("");msg << "Specify a type in a region type pair you want to crop. This flag should be used together with the egionPair flag";    TCLAP::ValueArg<std::string > typePairVecArgArg("a", "typePairVec", msg.str(), 0, typePairVecArgTemp, "std::vector<int>", commandLine); \
 \
    msg.str("");msg << "Specify a region in a region type pair you want to crop. This flag should be used together with the -typePair flag";    TCLAP::ValueArg<std::string > regionPairVecArgArg("b", "regionPairVec", msg.str(), 0, regionPairVecArgTemp, "std::vector<int>", commandLine); \
 \
    msg.str("");msg << "Echo the command line arguments (default: " << echoSwitch << ")"; \
    TCLAP::SwitchArg echoSwitchArg("", "echo", msg.str(), commandLine, echoSwitch); \
 \
    msg.str("");msg << "Produce xml description of command line arguments (default: " << xmlSwitch << ")"; \
    TCLAP::SwitchArg xmlSwitchArg("", "xml", msg.str(), commandLine, xmlSwitch); \
 \
    msg.str("");msg << "Address of a structure to store process information (progress, abort, etc.). (default: " << processInformationAddressString << ")"; \
    TCLAP::ValueArg<std::string > processInformationAddressStringArg("", "processinformationaddress", msg.str(), 0, processInformationAddressString, "std::string", commandLine); \
 \
    msg.str("");msg << "Filename in which to write simple return parameters (int, float, int-vector, etc.) as opposed to bulk return parameters (image, geometry, transform, measurement, table).";    TCLAP::ValueArg<std::string > returnParameterFileArg("", "returnparameterfile", msg.str(), 0, returnParameterFile, "std::string", commandLine); \
 \
try \
  { \
    /* Build a map of flag aliases to the true flag */ \
    std::map<std::string,std::string> flagAliasMap; \
    std::map<std::string,std::string> deprecatedFlagAliasMap; \
    std::map<std::string,std::string> longFlagAliasMap; \
    std::map<std::string,std::string> deprecatedLongFlagAliasMap; \
    /* Remap flag aliases to the true flag */ \
    std::vector<std::string> targs; \
    std::map<std::string,std::string>::iterator ait; \
    std::map<std::string,std::string>::iterator dait; \
    size_t ac; \
    for (ac=0; ac < static_cast<size_t>(argc); ++ac)  \
       {  \
       if (strlen(argv[ac]) == 2 && argv[ac][0]=='-') \
         { \
         /* short flag case */ \
         std::string tflag(argv[ac], 1, strlen(argv[ac])-1); \
         ait = flagAliasMap.find(tflag); \
         dait = deprecatedFlagAliasMap.find(tflag); \
         if (ait != flagAliasMap.end() || dait != deprecatedFlagAliasMap.end()) \
           { \
           if (ait != flagAliasMap.end()) \
             { \
             /* remap the flag */ \
             targs.push_back("-" + (*ait).second); \
             } \
           else if (dait != deprecatedFlagAliasMap.end()) \
             { \
             std::cout << "Flag \"" << argv[ac] << "\" is deprecated. Please use flag \"-" << (*dait).second << "\" instead. " << std::endl; \
             /* remap the flag */ \
             targs.push_back("-" + (*dait).second); \
             } \
           } \
         else \
           { \
           targs.push_back(argv[ac]); \
           } \
         } \
       else if (strlen(argv[ac]) > 2 && argv[ac][0]=='-' && argv[ac][1]=='-') \
         { \
         /* long flag case */ \
         std::string tflag(argv[ac], 2, strlen(argv[ac])-2); \
         ait = longFlagAliasMap.find(tflag); \
         dait = deprecatedLongFlagAliasMap.find(tflag); \
         if (ait != longFlagAliasMap.end() || dait != deprecatedLongFlagAliasMap.end()) \
           { \
           if (ait != longFlagAliasMap.end()) \
             { \
             /* remap the flag */ \
             targs.push_back("--" + (*ait).second); \
             } \
           else if (dait != deprecatedLongFlagAliasMap.end()) \
             { \
             std::cout << "Long flag \"" << argv[ac] << "\" is deprecated. Please use long flag \"--" << (*dait).second << "\" instead. " << std::endl; \
             /* remap the flag */ \
             targs.push_back("--" + (*dait).second); \
             } \
           } \
         else \
           { \
           targs.push_back(argv[ac]); \
           } \
         } \
       else if (strlen(argv[ac]) > 2 && argv[ac][0]=='-' && argv[ac][1]!='-') \
         { \
         /* short flag case where multiple flags are given at once ala */ \
         /* "ls -ltr" */ \
         std::string tflag(argv[ac], 1, strlen(argv[ac])-1); \
         std::string rflag("-"); \
         for (std::string::size_type fi=0; fi < tflag.size(); ++fi) \
           { \
           std::string tf(tflag, fi, 1); \
           ait = flagAliasMap.find(tf); \
           dait = deprecatedFlagAliasMap.find(tf); \
           if (ait != flagAliasMap.end() || dait != deprecatedFlagAliasMap.end()) \
             { \
             if (ait != flagAliasMap.end()) \
               { \
               /* remap the flag */ \
               rflag += (*ait).second; \
               } \
             else if (dait != deprecatedFlagAliasMap.end()) \
               { \
               std::cout << "Flag \"-" << tf << "\" is deprecated. Please use flag \"-" << (*dait).second << "\" instead. " << std::endl; \
               /* remap the flag */ \
               rflag += (*dait).second; \
               } \
             } \
           else \
             { \
             rflag += tf; \
             } \
           } \
         targs.push_back(rflag); \
         } \
       else \
         { \
         /* skip the argument without remapping (this is the case for any */ \
         /* arguments for flags */ \
         targs.push_back(argv[ac]); \
         } \
       } \
 \
   /* Remap args to a structure that CmdLine::parse() can understand*/ \
   std::vector<char*> vargs; \
   for (ac = 0; ac < targs.size(); ++ac) \
     {  \
     vargs.push_back(const_cast<char *>(targs[ac].c_str())); \
     } \
    commandLine.parse ( vargs.size(), (char**) &(vargs[0]) ); \
    fixedImageFileName = fixedImageFileNameArg.getValue(); \
    movingImageFileName = movingImageFileNameArg.getValue(); \
    movingImageID = movingImageIDArg.getValue(); \
    fixedImageID = fixedImageIDArg.getValue(); \
    registrationID = registrationIDArg.getValue(); \
    downsampleFactor = downsampleFactorArg.getValue(); \
    maxStepLength = maxStepLengthArg.getValue(); \
    minStepLength = minStepLengthArg.getValue(); \
    numberOfIterations = numberOfIterationsArg.getValue(); \
    translationScale = translationScaleArg.getValue(); \
    outputImageFileName = outputImageFileNameArg.getValue(); \
    outputTransformFileName = outputTransformFileNameArg.getValue(); \
    regionVecArgTemp = regionVecArgArg.getValue(); \
    typeVecArgTemp = typeVecArgArg.getValue(); \
    typePairVecArgTemp = typePairVecArgArg.getValue(); \
    regionPairVecArgTemp = regionPairVecArgArg.getValue(); \
    echoSwitch = echoSwitchArg.getValue(); \
    xmlSwitch = xmlSwitchArg.getValue(); \
    processInformationAddressString = processInformationAddressStringArg.getValue(); \
    returnParameterFile = returnParameterFileArg.getValue(); \
      { /* Assignment for regionVecArg */ \
      std::vector<std::string> words; \
      std::string sep(","); \
      splitString(regionVecArgTemp, sep, words); \
      for (unsigned int _j = 0; _j < words.size(); _j++) \
        { \
        regionVecArg.push_back(atoi(words[_j].c_str())); \
        } \
      } \
      { /* Assignment for typeVecArg */ \
      std::vector<std::string> words; \
      std::string sep(","); \
      splitString(typeVecArgTemp, sep, words); \
      for (unsigned int _j = 0; _j < words.size(); _j++) \
        { \
        typeVecArg.push_back(atoi(words[_j].c_str())); \
        } \
      } \
      { /* Assignment for typePairVecArg */ \
      std::vector<std::string> words; \
      std::string sep(","); \
      splitString(typePairVecArgTemp, sep, words); \
      for (unsigned int _j = 0; _j < words.size(); _j++) \
        { \
        typePairVecArg.push_back(atoi(words[_j].c_str())); \
        } \
      } \
      { /* Assignment for regionPairVecArg */ \
      std::vector<std::string> words; \
      std::string sep(","); \
      splitString(regionPairVecArgTemp, sep, words); \
      for (unsigned int _j = 0; _j < words.size(); _j++) \
        { \
        regionPairVecArg.push_back(atoi(words[_j].c_str())); \
        } \
      } \
  } \
catch ( TCLAP::ArgException e ) \
  { \
  std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; \
  return ( EXIT_FAILURE ); \
  }
#define GENERATE_ECHOARGS \
if (echoSwitch) \
{ \
std::cout << "Command Line Arguments" << std::endl; \
std::cout << "    fixedImageFileName: " << fixedImageFileName << std::endl; \
std::cout << "    movingImageFileName: " << movingImageFileName << std::endl; \
std::cout << "    movingImageID: " << movingImageID << std::endl; \
std::cout << "    fixedImageID: " << fixedImageID << std::endl; \
std::cout << "    registrationID: " << registrationID << std::endl; \
std::cout << "    downsampleFactor: " << downsampleFactor << std::endl; \
std::cout << "    maxStepLength: " << maxStepLength << std::endl; \
std::cout << "    minStepLength: " << minStepLength << std::endl; \
std::cout << "    numberOfIterations: " << numberOfIterations << std::endl; \
std::cout << "    translationScale: " << translationScale << std::endl; \
std::cout << "    outputImageFileName: " << outputImageFileName << std::endl; \
std::cout << "    outputTransformFileName: " << outputTransformFileName << std::endl; \
std::cout << "    regionVecArg: "; \
for (unsigned int _i =0; _i < regionVecArg.size(); _i++) \
{ \
std::cout << regionVecArg[_i] << ", "; \
} \
std::cout <<std::endl; \
std::cout << "    typeVecArg: "; \
for (unsigned int _i =0; _i < typeVecArg.size(); _i++) \
{ \
std::cout << typeVecArg[_i] << ", "; \
} \
std::cout <<std::endl; \
std::cout << "    typePairVecArg: "; \
for (unsigned int _i =0; _i < typePairVecArg.size(); _i++) \
{ \
std::cout << typePairVecArg[_i] << ", "; \
} \
std::cout <<std::endl; \
std::cout << "    regionPairVecArg: "; \
for (unsigned int _i =0; _i < regionPairVecArg.size(); _i++) \
{ \
std::cout << regionPairVecArg[_i] << ", "; \
} \
std::cout <<std::endl; \
std::cout << "    echoSwitch: " << echoSwitch << std::endl; \
std::cout << "    xmlSwitch: " << xmlSwitch << std::endl; \
std::cout << "    processInformationAddressString: " << processInformationAddressString << std::endl; \
std::cout << "    returnParameterFile: " << returnParameterFile << std::endl; \
}
#define GENERATE_ProcessInformationAddressDecoding \
ModuleProcessInformation *CLPProcessInformation = 0; \
if (processInformationAddressString != "") \
{ \
sscanf(processInformationAddressString.c_str(), "%p", &CLPProcessInformation); \
}
#define PARSE_ARGS GENERATE_LOGO;GENERATE_XML;GENERATE_TCLAP;GENERATE_ECHOARGS;GENERATE_ProcessInformationAddressDecoding;
