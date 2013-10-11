#include <stdio.h>
#include <algorithm>
const int MAXNUMBOOKS = 10001;

int FindBookPrice (int bookPrices[MAXNUMBOOKS], int nBooks, int bookPrice, int& priceIndex)
{
    int startIndex = 0;
    int endIndex = nBooks - 1;
    int mid = 0;
    priceIndex = -1;
    while (startIndex <= endIndex) {
        mid = startIndex + ((endIndex - startIndex) / 2);
        if (bookPrice < bookPrices[mid]) {
            endIndex = mid - 1;
        }
        else if (bookPrice > bookPrices[mid]) {
            startIndex = mid + 1;
        }
        else {
            priceIndex = mid;
            return bookPrice;
        }
    }

    return -1;
}

void GetBookPrices(int bookPrices[MAXNUMBOOKS], int nBooks, int budget, int& bookPrice1, int& bookPrice2)
{
    int price1 = 0;
    int price2 = 0;
    int diff = budget; /// init to a big enough number
    int curDiff = 0;
    int price2Index = 0;
    std::sort(bookPrices, bookPrices + nBooks);

    for (int i = 0; i < nBooks; ++i) {
        if (bookPrices[i] >= budget) break;

        price1 = bookPrices[i];
        price2 = budget - price1;
        price2 = FindBookPrice(bookPrices, nBooks, price2, price2Index);
        if (price2 != -1 && price2Index != i) {
            if (price1 > price2) {
                std::swap(price1, price2);
            }
            curDiff = price2 - price1;
            if (curDiff < diff) {
                diff = curDiff;
                bookPrice1 = price1;
                bookPrice2 = price2;
            }
        }
    }
}

int main()
{
    int bookPrices[MAXNUMBOOKS] = {0};
    int nBooks = 0;
    int budget = 0;
    int bookPrice1 = 0;
    int bookPrice2 = 0;

    while (scanf("%d", &nBooks) != EOF) {
        for (int i = 0; i < nBooks; ++i) {
            scanf("%d", &bookPrices[i]);
        }
        scanf("%d", &budget);

        bookPrice1 = 0;
        bookPrice2 = 0;
        GetBookPrices(bookPrices, nBooks, budget, bookPrice1, bookPrice2);

        printf ("Peter should buy books whose prices are %d and %d.\n\n", bookPrice1, bookPrice2);
    }

    return 0;
}
