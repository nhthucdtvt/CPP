#!/bin/bash

# Chạy Producer
./producer &

# Chạy Broker
./broker &

# Chạy Consumer
./consumer &
