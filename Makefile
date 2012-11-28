# fun with makefiles
# fastlights and testlights
#
fastlights: fastlights.c lightnames.h lightnames.c layoutloader.h layoutloader.c \
		lightnames.gperf sing.h singtime.c singtime.h
	gcc fastlights.c layoutloader.c lightnames.c singtime.c -o fastlights -lrt -lyajl -DOLIMEX
	sudo chown root:root fastlights
	sudo chmod 6711 fastlights

testlights: testlights.c lightnames.h lightnames.c layoutloader.h layoutloader.c \
		lightnames.gperf sing.h singtime.c singtime.h
	gcc testlights.c layoutloader.c lightnames.c singtime.c -o testlights -lrt -lyajl -DOLIMEX
	sudo chown root:root testlights
	sudo chmod 6711 testlights
