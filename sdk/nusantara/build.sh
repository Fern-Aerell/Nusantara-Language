# /bin/bash

ARG1="$1"

if [[ $ARG1 = "release" ]] || [[ $ARG1 = "debug" ]]
then 	
	echo Formating...
	find src include -iname *.h -o -iname *.cpp -o -iname *.cc | xargs clang-format -i
	echo Configuration...
	cmake --preset $ARG1
	echo Building...
	cmake --build --preset $ARG1
	echo Copy compile_commands.json
	cp build/release/compile_commands.json ./
	echo Running...
	./build/release/nusantara
else
	echo Tipe build tidak valid
fi
