#include <stdio.h>

int main() {
    int totalHours = 0, totalMinutes = 0;
    int hours, minutes;

    printf("Program to calculate the total sum of hours and minutes.\n");
    printf("Enter a negative value for either hours or minutes to end.\n");

    while (1) {
        printf("Enter hours: ");
        scanf("%d", &hours);
        
        printf("Enter minutes: ");
        scanf("%d", &minutes);

        if (hours < 0 || minutes < 0) {
            break;
        }

        totalHours += hours;
        totalMinutes += minutes;

        // Convert minutes into hours if there are more than 60 minutes
        totalHours += totalMinutes / 60;
        totalMinutes = totalMinutes % 60;
    }

    printf("The total sum is %d hours and %d minutes.\n", totalHours, totalMinutes);
    return 0;
}
