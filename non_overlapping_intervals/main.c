#include <stdlib.h>

int compareIntervals(const void *a, const void *b) {
	int *intervalA = *(int **)a;
	int *intervalB = *(int **)b;

	return intervalA[1] - intervalB[1];
}

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize) {
	if (intervalsSize <= 0) {
		return 0;
	}

	qsort(intervals, intervalsSize, sizeof(int *), compareIntervals);

	int removals = 0;
	int last_end = intervals[0][1];

	for (int i = 1; i < intervalsSize; i++) {
		int current_start = intervals[i][0];
		int current_end = intervals[i][1];

		if (current_start < last_end) {
			removals++;
		} else {
			last_end = current_end;
		}
	}

	return removals;
}
