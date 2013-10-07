#include <stdio.h>
const int MAXTRACKS = 21; /// assuming that # tracks does not exceed 20 and each track should at least be 1 min

int FitTracksOntoTape(int tracks[MAXTRACKS], int nTracks, int trackIndex, int totalAvailableLength, int currentLength)
{
    if (totalAvailableLength == currentLength)
        return currentLength;

    int possibleLength = 0;
    int maxPossibleLenth = currentLength;
    for (int i = trackIndex; i < nTracks; ++i) {
        if ((tracks[i] + currentLength) <= totalAvailableLength) {
            printf("track len=%d cur_len+track_len=%d\n", tracks[i], (tracks[i] + currentLength));
            possibleLength =
                FitTracksOntoTape(tracks, nTracks, (i+1), totalAvailableLength, (tracks[i] + currentLength));
            printf("possible len=%d\n", possibleLength);
            if (possibleLength > maxPossibleLenth)
                maxPossibleLenth = possibleLength;
        }
        else {
            printf("track len=%d cur_len=%d (excluding track_len)\n", tracks[i], (currentLength));
            possibleLength =
                FitTracksOntoTape(tracks, nTracks, (i+1), totalAvailableLength, (currentLength));
            printf("possible len=%d\n", possibleLength);
            if (possibleLength > maxPossibleLenth)
                maxPossibleLenth = possibleLength;
        }
    }

    return maxPossibleLenth;
}
int main()
{
    int tracks[MAXTRACKS] = {0};
    int totalTrackLength = 0;
    int nTracks = 0;
    while (scanf("%d", &totalTrackLength) != EOF) {
        scanf("%d", &nTracks);
        for (int i = 0; i < nTracks; ++i) {
            scanf("%d", &tracks[i]);
        }
        printf("%d\n", FitTracksOntoTape(tracks, nTracks, 0, totalTrackLength, 0));
    }
    return 0;
}
