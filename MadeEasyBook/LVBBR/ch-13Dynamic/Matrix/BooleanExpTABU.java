import java.util.*;

class Solution {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String s1 = scn.next();
        String s2 = scn.next();

        System.out.println(solution(s1, s2));
    }

    private static int solution(String str1, String str2) {
        int n = str1.length();
        int[][] dpt = new int[n][n];
        int[][] dpf = new int[n][n];

        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; j++, i++) {
                if (g == 0) {
                    char ch = str1.charAt(i);
                    if (ch == 'T') {
                        dpt[i][j] = 1;
                        dpf[i][j] = 0;
                    } else {
                        dpt[i][j] = 0;
                        dpf[i][j] = 1;
                    }
                } else {
                    for (int k = i; k <= j - 1; k++) {
                        char oprtr = str2.charAt(k);
                        int Lt = dpt[i][k];
                        int Rt = dpt[k + 1][j];

                        int Lf = dpf[i][k];
                        int Rf = dpf[k + 1][j];

                        switch (oprtr) {
                            case '&':
                                dpt[i][j] += Lt * Rt;
                                dpf[i][j] += Lt * Rf + Lf * Rf + Lf * Rt;
                                break;
                            case '|':
                                dpt[i][j] += Lt * Rt + Lt * Rf + Lf * Rt;
                                dpf[i][j] += Lf * Rf;
                                break;
                            case '^':
                                dpt[i][j] += Lt * Rf + Lf * Rt;
                                dpf[i][j] += Lt * Rt + Lf * Rf;
                                break;
                        }
                    }
                }
            }
        }

        return dpt[0][n - 1];
    }
}

/*
TFTF
&|^
 */