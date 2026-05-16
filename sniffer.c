#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open the network interface
    // assign it to promisicious mode, toimeout for 1000 seconds
 
    handle = pcap_open_live("en0", 65535, 1, 1000, errbuf);
    
    //check for null values
    if (handle == NULL) {
        fprintf(stderr, "Could not open device: %s\n", errbuf);
        return 1;
    }
    
    printf("Listening on en0...\n");

  
    struct pcap_pkthdr *header;
    const unsigned char *packet;
    int result;

    while ((result = pcap_next_ex(handle, &header, &packet)) >= 0) {
        if (result == 0) continue;  // Timeout, no packet

      
        printf("Captured packet: %d bytes\n", header->len);
    }

 
    pcap_close(handle);
    return 0;
}
