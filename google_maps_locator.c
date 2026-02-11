#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define BASE_URL "https://www.google.com/maps/place/"
#define MAX_PLACE_LENGTH 512
#define MAX_URL_LENGTH 1024


int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <place_to_search>", argv[0]);
        exit(EXIT_FAILURE);
    }

    char final_url[MAX_URL_LENGTH];
    int written = snprintf(final_url, sizeof(final_url), "%s%s", BASE_URL, argv[1]);

    if (written < 0 || written >= (int)sizeof(final_url))
    {
        fprintf(stderr, "Error: place is too long.\n");
        return EXIT_FAILURE;
    }

    char cmd[MAX_URL_LENGTH + 64];

#ifdef _WIN32
    snprintf(cmd, sizeof(cmd), "start \"\" chrome \"%s\"", final_url);
    system(cmd);

#elif __APPLE__
    snprintf(cmd, sizeof(cmd), "open -a \"Google Chrome\" \"%s\"", final_url);
    system(cmd);

#else
    snprintf(cmd, sizeof(cmd), "google-chrome \"%s\"", final_url);
    system(cmd);
#endif

    return EXIT_SUCCESS;
}
