#include <stdio.h>

struct Time {
    int hour;
    int minute;
};

// Convert to GMT
int toGMT(int localMinutes, int offset) {
    localMinutes -= offset * 60;
    localMinutes = (localMinutes + 1440) % 1440;
    return localMinutes;
}

// Convert back to local
int toLocal(int gmtMinutes, int offset) {
    gmtMinutes += offset * 60;
    gmtMinutes = (gmtMinutes + 1440) % 1440;
    return gmtMinutes;
}

// Print time in HH:MM
void printTime(int minutes) {
    int h = minutes / 60;
    int m = minutes % 60;
    if (h < 10) printf("0");
    printf("%d:", h);
    if (m < 10) printf("0");
    printf("%d", m);
}

int main() {
    int offset1, offset2;
    int slot1, slot2, duration;

    struct Time slots1[100], slots2[100];

    // Inputs
    printf("Enter offset of Person 1 [in hours]: ");
    scanf("%d", &offset1);

    printf("Enter number of slots for Person 1: ");
    scanf("%d", &slot1);

    printf("Enter time slot for Person 1 (hh mm hh mm):\n");
    for (int i = 0; i < slot1; i++) {
        int sh, sm, eh, em;
        scanf("%d %d %d %d", &sh, &sm, &eh, &em);
        slots1[i].hour = toGMT(sh * 60 + sm, offset1);
        slots1[i].minute = toGMT(eh * 60 + em, offset1);
    }

    printf("Enter offset of Person 2 [in hours]: ");
    scanf("%d", &offset2);

    printf("Enter number of slots for Person 2: ");
    scanf("%d", &slot2);

    printf("Enter time slot for Person 2 (hh mm hh mm):\n");
    for (int j = 0; j < slot2; j++) {
        int sh, sm, eh, em;
        scanf("%d %d %d %d", &sh, &sm, &eh, &em);
        slots2[j].hour = toGMT(sh * 60 + sm, offset2);
        slots2[j].minute = toGMT(eh * 60 + em, offset2);
    }

    printf("Enter the duration (in minutes): ");
    scanf("%d", &duration);

    int found = 0;

    printf("\nAvailable slots:\n");
    for (int i = 0; i < slot1; i++) {
        for (int j = 0; j < slot2; j++) {
            int start = (slots1[i].hour > slots2[j].hour) ? slots1[i].hour : slots2[j].hour;
            int end = (slots1[i].minute < slots2[j].minute) ? slots1[i].minute : slots2[j].minute;

            if (end - start >= duration) {
                found = 1;

                printf("Person 1: ");
                printTime(toLocal(start, offset1));
                printf(" - ");
                printTime(toLocal(start + duration, offset1));
                printf("\n");

                printf("Person 2: ");
                printTime(toLocal(start, offset2));
                printf(" - ");
                printTime(toLocal(start + duration, offset2));
                printf("\n\n");
            }
        }
    }

    if (!found) {
        printf("\nNo common slot found.\n");
    }

    return 0;
}