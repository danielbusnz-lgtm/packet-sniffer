# packet-sniffer

Captures network packets and prints their size.

## Build

```
gcc -o sniffer sniffer.c -lpcap
```

## Run

```
sudo ./sniffer
```

Requires root to capture packets.

## Requirements

- libpcap (pre-installed on macOS)
