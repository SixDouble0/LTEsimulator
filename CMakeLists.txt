# CMakeList.txt: projekt CMake dla elementu LTEsimulator, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (LTEsimulator "main.cpp" "src/User.cpp" "src/Cell.cpp" "src/Scheduler.cpp" "src/NetworkManager.cpp" "src/Utilis.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LTEsimulator PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
