#!/bin/bash

wiadomosc = $1

if [[ "${wiadomosc:0:1}" = [a-zA-Z] ]] ; then
	if [[ ${wiadomosc} == *[[:ascii:]]* ]] ; then
		sprawdz = `echo ${wiadomosc} | aspell list -l pl`
		
		if [[ "${sprawdz}" == "" ]] ; then
			echo "ok";
		else
			echo "nie polskie";
		fi
	else
		echo "nie ASCII";
	fi
else
	echo "niech sie zacznie od litery";
fi
