#!/usr/bin/sh
orphans=$(ps -ef | awk -v user=vidyut '$1 == user && $3 == 1 {print $2}')
echo "Plausible orphans are: $orphans"
