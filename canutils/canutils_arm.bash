#!/bin/bash

if ! command -v jq &> /dev/null
then
    echo "jq is not installed. see https://stedolan.github.io/jq/"
    exit
fi

RELEASE=$(curl -sL https://api.github.com/repos/eagletrt/canutils/releases/latest | jq -r ".tag_name")

echo "Downloading release $RELEASE"

wget -q "https://github.com/eagletrt/canutils/releases/download/$RELEASE/eagle_cansniffer_arm" -O eagle_cansniffer
chmod +x eagle_cansniffer

wget -q "https://github.com/eagletrt/canutils/releases/download/$RELEASE/eagle_candump_arm" -O eagle_candump
chmod +x eagle_candump
