/**********************************************************************

  Audacity: A Digital Audio Editor

  AudacityHeaders.h

  Dominic Mazzoni

  This is not a normal include file - it's currently only used
  on Mac OS X as a "precompiled header" file that's automatically
  included by all source files, resulting in roughly a 2x increase
  in compilation speed.

  When gcc 3.4 is released, it will have precompiled header support
  on other platforms, and this file could be adapted to support
  precompiled headers on Linux, etc.

**********************************************************************/

#include "Audacity.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



#include <wx/wxprec.h>
#include <wx/filefn.h>
#include <wx/ffile.h>
#include <wx/filename.h>
#include <wx/progdlg.h>
#include <wx/textfile.h>
#include <wx/thread.h>
#include <wx/tooltip.h>

#ifdef __WXMAC__
#include <wx/mac/private.h>
#endif

#if defined(_MSC_VER) && defined(WXUSINGDLL)
/* zlib functions are called in in libid3tag code,
   zlib is in the wxBase DLL, however those functions are not exported for
   external usage from that DLL, so, unfortunately we must statically link
   to the wxWidgets zlib in order to use those zlib functions.
   zlib is automatically linked to by msvc/wx/setup.h prior to wxWidgets 2.9.4.
   Starting there, it is no longer linked to if WXUSINGDLL. So we must
   statically link to zlib if we're using wxWidgets 2.9.4 or later.*/
#if (wxMAJOR_VERSION >= 3) || \
    (wxMAJOR_VERSION == 2) && (wxMINOR_VERSION == 9) && (wxRELEASE_NUMBER >= 4)
#pragma comment(lib, wx3RD_PARTY_LIB_NAME("zlib"))
#endif
#endif

#include "audacity/Types.h"

#include "AColor.h"
#include "AudacityApp.h"
#include "AudioIO.h"
#include "BlockFile.h"
#include "DirManager.h"
#include "Envelope.h"
#include "FFT.h"
#include "FileFormats.h"
#include "FreqWindow.h"
#include "ImageManipulation.h"
#include "Internat.h"
#include "LabelTrack.h"
#include "Mix.h"
#include "NoteTrack.h"
#include "Prefs.h"
#include "Project.h"
#include "Resample.h"
#include "SampleFormat.h"
#include "Sequence.h"
#include "TimeTrack.h"
#include "Track.h"
#include "UndoManager.h"
#include "ViewInfo.h"
#include "WaveTrack.h"
#include "widgets/ASlider.h"
#include "widgets/ProgressDialog.h"
#include "widgets/Ruler.h"
#include "xml/XMLTagHandler.h"

// PRL:  These lines allow you to remove Project.h above.
// They must be included before the definition of macro new below.
#include <set>
#include <map>

//#ifdef __WXMSW__
// Enable this to diagnose memory leaks too!
//    #include <wx/msw/msvcrt.h>      // redefines the new() operator
//#endif

#if __WXMSW__
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif
#endif
