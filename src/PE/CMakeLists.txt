set(LIEF_PE_SRC
  "${CMAKE_CURRENT_LIST_DIR}/Binary.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Builder.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Builder.tcc"
  "${CMAKE_CURRENT_LIST_DIR}/CodeIntegrity.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/CodeView.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/CodeViewPDB.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Convert.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/DataDirectory.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Debug.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/DelayImport.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/DelayImportEntry.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/DosHeader.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/EnumToString.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Export.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/ExportEntry.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Header.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Import.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/ImportEntry.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/OptionalHeader.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Parser.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Parser.tcc"
  "${CMAKE_CURRENT_LIST_DIR}/Pogo.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/PogoEntry.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Relocation.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/RelocationEntry.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/ResourceData.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/ResourceDirectory.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/ResourceNode.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/ResourcesManager.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/ResourcesParser.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/RichEntry.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/RichHeader.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Section.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Symbol.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/TLS.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/utils.cpp"
)


set(LIEF_PE_INCLUDE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/AuxiliarySymbol.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Binary.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Builder.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/CodeIntegrity.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/CodeView.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/CodeViewPDB.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/DataDirectory.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Debug.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/DelayImport.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/DelayImportEntry.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/DosHeader.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/EnumToString.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Export.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/ExportEntry.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Header.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Import.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/ImportEntry.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/OptionalHeader.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Parser.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Relocation.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/RelocationEntry.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/ResourceData.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/ResourceDirectory.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/ResourceNode.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/ResourcesManager.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/RichEntry.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/RichHeader.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Section.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/Symbol.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/TLS.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/enums.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/undef.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/utils.hpp"
  "${CMAKE_CURRENT_LIST_DIR}/Structures.hpp"
  "${CMAKE_CURRENT_LIST_DIR}/ResourcesParser.hpp"
)

set(LIEF_PE_UTILS_INCLUDE_FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/PE/utils/ordinals_lookup_tables/libraries_table.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/PE/utils/ordinals_lookup_tables/kernel32_dll_lookup.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/PE/utils/ordinals_lookup_tables/ntdll_dll_lookup.hpp"
)

# Hash Part
# =========
set(LIEF_PE_HASH_SRC "${CMAKE_CURRENT_LIST_DIR}/hash.cpp")
set(LIEF_PE_HASH_HDR "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/hash.hpp")

# JSON Public API: Always present
list(APPEND LIEF_PE_SRC      "${CMAKE_CURRENT_LIST_DIR}/json_api.cpp")
list(APPEND LIEF_PE_INC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/LIEF/PE/json.hpp")

# JSON Impl
if (LIEF_ENABLE_JSON)
  list(APPEND LIEF_PE_SRC       "${CMAKE_CURRENT_LIST_DIR}/json.cpp")
  list(APPEND LIEF_PE_INC_FILES "${CMAKE_CURRENT_LIST_DIR}/json_internal.hpp")
endif()

list(APPEND LIEF_PE_SRC ${LIEF_PE_HASH_SRC})
list(APPEND LIEF_PE_INCLUDE_FILES ${LIEF_PE_HASH_HDR})


source_group("Source Files\\PE"                                FILES ${LIEF_PE_SRC})
source_group("Header Files\\PE"                                FILES ${LIEF_PE_INCLUDE_FILES})
source_group("Header Files\\PE\\utils\\Ordinals Lookup Tables" FILES ${LIEF_PE_UTILS_INCLUDE_FILES})

if (LIEF_PE)
  target_sources(LIB_LIEF PRIVATE
    ${LIEF_PE_SRC}
    ${LIEF_PE_INCLUDE_FILES}
    ${LIEF_PE_SIG_INCLUDE_FILES}
    ${LIEF_PE_RESOURCES_INCLUDE_FILES}
    ${LIEF_PE_UTILS_INCLUDE_FILES}
  )
endif()

include("${CMAKE_CURRENT_LIST_DIR}/signature/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/LoadConfigurations/CMakeLists.txt")
include("${CMAKE_CURRENT_LIST_DIR}/resources/CMakeLists.txt")
