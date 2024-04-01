#include <stdio.h>
#include "survey.h"

void add(int answer[], int *count, int item) {
    int i = *count - 1;
    while (i >= 0 && answer[i] > item) {
        answer[i + 1] = answer[i];
        i--;
    }
    answer[i + 1] = item;
    (*count)++;
}

float mean(int answer[], int size) {
	int i;
    float sum = 0;
    for (i = 0; i < size; i++) {
        sum += answer[i];
    }
    return sum / size;
}

float median(int answer[], int size) {
    if (size % 2 == 0) {
        return (answer[size / 2 - 1] + answer[size / 2]) / 2.0;
    } else {
        return answer[size / 2];
    }
}

int max(int answer[], int size) {
    int max_val = answer[0];
    	int i;
    for (i = 1; i < size; i++) {
        if (answer[i] > max_val) {
            max_val = answer[i];
        }
    }
    return max_val;
}

int min(int answer[], int size) {
		int i;
    int min_val = answer[0];
    for (i = 1; i < size; i++) {
        if (answer[i] < min_val) {
            min_val = answer[i];
        }
    }
    return min_val;
}

int range(int answer[], int size) {
    return max(answer, size) - min(answer, size);
}

float mode(int freq[], int freqsize, int answer[], int size, int modes[], int *modecount) {
		int i;
    for (i = 0; i < freqsize; i++) {
        freq[i] = 0; // Initialize frequency array to 0
    }

    for (i = 0; i < size; i++) {
        freq[answer[i]]++;
    }
    
    int max_freq = 0;
    *modecount = 0; // Initialize mode count to 0
    
    for (i = 0; i < freqsize; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            *modecount = 1;
            modes[*modecount - 1] = i;
        } else if (freq[i] == max_freq) {
            (*modecount)++;
            modes[*modecount - 1] = i;
        }
    }
    
    return max_freq;
}

void histogram(int freq[], int size) {
		int i, j;
    printf("Histogram:\n");
    for (i = 1; i < size; i++) {
        printf("%d: ", i);
        for (j = 0; j < freq[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}
