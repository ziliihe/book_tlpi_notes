#include <getopt.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int opt;
    int long_index = 0;
    struct option long_options[] = {
        {"file", required_argument, 0, 'f'},
        {"name", required_argument, 0, 'n'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "f:n:h", long_options, &long_index)) != -1) {
        switch (opt) {
            case 'f':
                printf("File: %s\n", optarg);
                break;
            case 'n':
                printf("Name: %s\n", optarg);
                break;
            case 'h':
                printf("Usage: %s [-f file] [-n name] [--help]\n", argv[0]);
                return 0;
            case '?':
                printf("Unknown option: %c\n", optopt);
                break;
            case ':':
                printf("Option requires an argument: %c\n", optopt);
                break;
            default:
                printf("Unexpected option: %c\n", opt);
                break;
        }
    }

    return 0;
}
