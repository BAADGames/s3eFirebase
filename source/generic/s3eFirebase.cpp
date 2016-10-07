/*
Generic implementation of the s3eFirebase extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eFirebase_internal.h"
s3eResult s3eFirebaseInit()
{
    //Add any generic initialisation code here
    return s3eFirebaseInit_platform();
}

void s3eFirebaseTerminate()
{
    //Add any generic termination code here
    s3eFirebaseTerminate_platform();
}

void s3eFirebaseInitialize()
{
	s3eFirebaseInitialize_platform();
}
