#include <stdio.h>

int main()
{
    int length = 0, lengthDecimal = 0;
    int width = 0, widthDecimal = 0;
    int depth = 0, depthDecimal = 0;
    int totalAllowedBaggages = 0;
    int weight = 0, weightDecimal;
    int ncases = 0;
    scanf("%d", &ncases);

    while (ncases--) {
        scanf("%d.%d %d.%d %d.%d %d.%d", &length, &lengthDecimal, &width, &widthDecimal, &depth, &depthDecimal, &weight, &weightDecimal);
        //printf("Debug: %d:%d %d:%d %d:%d %d:%d\n", length, lengthDecimal, width, widthDecimal, depth, depthDecimal, weight, weightDecimal);
        length *= 100;
        length += lengthDecimal;

        width *= 100;
        width += widthDecimal;

        depth *= 100;
        depth += depthDecimal;

        weight *= 1000;
        weight += weightDecimal;

        //printf("Debug: %d %d %d %d\n", length, width, depth, weight);

        if (length <= 5600 && width <= 4500 && depth <= 2500 && weight <= 7000) {
            totalAllowedBaggages += 1;
            printf("%d\n", 1);
        }
        else {
            if (((length + width + depth) <= 12500) && weight <= 7000) {
                totalAllowedBaggages += 1;
                printf("%d\n", 1);
            }
            else {
                printf("%d\n", 0);
            }
        }
    }
    printf("%d\n", totalAllowedBaggages);
    return 0;
}
