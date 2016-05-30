#!/bin/bash
git clone https://github.com/nathanweeks/ipcmd.git
gdzie = 'pwd'
cd $gdzie/ipcmd
make
make check
