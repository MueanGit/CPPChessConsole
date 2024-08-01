git clone https://github.com/MueanGit/CPPChessConsole.git
cd CPPChessConsole
mkdir build
cd build
cmake -G "Unix Makefiles" ../source/
cmake --build .

cd Debug
./Chess