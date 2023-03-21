# CMakeList.txt : CMake project for Poker, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Poker "Poker.cpp" "Poker.h" "Headers/Model/Card.h" "Src/Model/Card.cpp" "Headers/Model/Deck.h" "Src/Model/Deck.cpp")

include_directories(headers)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Poker PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
