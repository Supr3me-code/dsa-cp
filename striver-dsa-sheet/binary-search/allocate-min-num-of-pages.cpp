/*
Given an array of integers A of size N and an integer B.

College library has N bags,the ith book has A[i] number of pages.

You have to allocate books to B number of students so that maximum number of
pages alloted to a student is minimum.

A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be
allocated book 1 and book 3, skipping book 2. Calculate and return that minimum
possible number.

NOTE: Return -1 if a valid assignment is not possible.
*/

bool isSafe(vector<int> &A, int m, int n, int mid) {
    // distributing mid pages to each student
    int numberOfStudents = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        // we wanted to assign "mid" pages at max to a single student but this
        // book has more pages
        if (A[i] > mid) return false;

        // cannot assign this book to the current student so now we move to the
        // next student
        if (A[i] + sum > mid) {
            numberOfStudents++;
            sum = A[i];

            // duh
            if (numberOfStudents > m) return false;
        } else {
            // we still have space to add more pages to the current student
            // before it crosses "mid" number of pages
            sum += A[i];
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int n = A.size();

    // if number of books is leff than the number of students
    if (n < B) return -1;

    // sum of all pages (maximum taht can be alloted to a single student)
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }

    // we know that the answer lies between start and end
    int start = 0;
    int end = sum;
    int result;
    while (start <= end) {
        int mid = (start + end) / 2;

        // check if we give "mid" number of pages to a single student then after
        // that do we have enough books to give atleast 1 to each remaining
        // student?
        if (isSafe(A, B, n, mid)) {
            // if true.. that means we have got a solution, now we'll check if
            // mid can be minimized further.. so we take the left side
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}
