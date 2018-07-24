/**
 *  @file
 *  @copyright defined in VAC/LICENSE.txt
 */

#include <VACio/utilities/tempdir.hpp>

#include <cstdlib>

namespace VACio { namespace utilities {

fc::path temp_directory_path()
{
   const char* VAC_tempdir = getenv("VAC_TEMPDIR");
   if( VAC_tempdir != nullptr )
      return fc::path( VAC_tempdir );
   return fc::temp_directory_path() / "VAC-tmp";
}

} } // VACio::utilities
