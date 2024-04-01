#include <stdio.h>
#include "survey.h"

#define MAX_RESPONDENTS 100

// ANSI color escape codes
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main() {
    int responses[MAX_RESPONDENTS];
    int count = 0;
    int freq[10] = {0}; // Frequencies of responses
    int modes[MAX_RESPONDENTS]; // Array to store modes
    int modecount = 0; // Count of modes
    
    // Input responses
    printf("Enter responses (between 1 and 9, -1 to stop):\n");
    int response;
    while (1) {
        scanf("%d", &response);
        if (response == -1) {
            break;
        }
        add(responses, &count, response);
    }
    
    // Compute statistics
    float meanValue = mean(responses, count);
    float medianValue = median(responses, count);
    int minResponse = min(responses, count);
    int maxResponse = max(responses, count);
    int rangeValue = range(responses, count);
    
    // Print statistics
    printf(ANSI_COLOR_CYAN "Mean: %.2f\n" ANSI_COLOR_RESET, meanValue);
    printf(ANSI_COLOR_MAGENTA "Median: %.2f\n" ANSI_COLOR_RESET, medianValue);
    printf(ANSI_COLOR_YELLOW "Mode: %.2f\n" ANSI_COLOR_RESET, mode(freq, 10, responses, count, modes, &modecount));
    printf(ANSI_COLOR_RED "Min: %d\n" ANSI_COLOR_RESET, minResponse);
    printf(ANSI_COLOR_GREEN "Max: %d\n" ANSI_COLOR_RESET, maxResponse);
    printf(ANSI_COLOR_BLUE "Range: %d\n" ANSI_COLOR_RESET, rangeValue);
    printf(ANSI_COLOR_GREEN "Histogram:\n" ANSI_COLOR_RESET);
    histogram(freq, 10);
    
    return 0;
}
