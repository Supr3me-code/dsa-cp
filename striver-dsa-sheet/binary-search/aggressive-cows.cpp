/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The
stalls are located along a straight line at positions x1,...,xN (0 <= xi <=
1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive
towards each other once put into a stall. To prevent the cows from hurting each
other, FJ wants to assign the cows to the stalls, such that the minimum distance
between any two of them is as large as possible. What is the largest minimum
distance?
*/

#include <bits/stdc++.h>

bool isPossible(vector<int> rooms, int numberOfRooms, int numberOfPlayers,
                int mid) {
    int coord = rooms[0];
    int count = 1;

    for (int i = 1; i < numberOfRooms; i++) {
        if ((rooms[i] - coord) >= mid) {
            count++;
            coord = rooms[i];
        }
        if (count >= numberOfPlayers) return true;
    }
    return false;
}

int chessTournament(vector<int> rooms, int numberOfRooms, int numberOfPlayers) {
    sort(rooms.begin(), rooms.end());
    int low = 1;
    int high = rooms[numberOfRooms - 1] - rooms[0];

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(rooms, numberOfRooms, numberOfPlayers, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
    // Write your code here
}