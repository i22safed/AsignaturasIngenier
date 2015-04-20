#!/bin/bash

df | sed -r -e 's/^([^ ]+)[ ]+([^ ]+)[ ]+.*$/Primer+a col.'
