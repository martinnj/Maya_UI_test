// 
// File: pluginMain.cpp
//
// Author: Maya Plug-in Wizard 2.0
//
#include <stdio.h>
#include <maya/MString.h>
#include <maya/MArgList.h>
#include <maya/MFnPlugin.h>
#include <maya/MPxCommand.h>
#include <maya/MIOStream.h>

//#include <maya/MGlobal.h> // Needed to execute commands.

class output : public MPxCommand
{
    public:
        MStatus doIt( const MArgList& args );
        static void* creator();
};

MStatus output::doIt( const MArgList& args ) {
    cout << args.asString( 0 ).asChar() << endl;	
    return MS::kSuccess;
}

void* output::creator() {
    return new output();
}

MStatus initializePlugin( MObject obj )
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "Martin Jørgensen", "2013", "Any");
	cout << "Registering plugin... ";
	// Add plug-in feature registration here
	//
	plugin.registerCommand("write",output::creator);


	cout << "Done" <<endl;
	status = MS::kSuccess;
	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj );

	cout << "Deregistering plugin... ";
	// Add plug-in feature deregistration here
	//
	plugin.deregisterCommand("write");


	
	cout << "Done" <<endl;
	status = MS::kSuccess;
	return status;
}
