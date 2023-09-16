This is the tester environment for black box and white box. 
Properties: libraries, dependencies are added. 

Please be very careful with configuring any property values of this project. 
May result in linking errors.

Current property values:
Target Name:	$(ProjectName)

c/c++ GENERAL > Additional Include Directories:
	$(ProjectDir)..\Departure_planner
	$(VCInstallDir)UnitTest\include

linker general, Additional Library Directories:
	$(ProjectDir)..\Departure_planner\x64\Debug
	$(ProjectDir)..\Departure_planner
	$(VCInstallDir)UnitTest\lib

linker Input, Additional Dependencies:
	$(ProjectDir)..\Departure_planner\x64\Debug\helper.obj
	$(ProjectDir)..\Departure_planner\x64\Debug\mainleave.obj
	