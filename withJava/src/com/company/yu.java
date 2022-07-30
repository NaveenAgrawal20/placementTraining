package com.company;

import java.util.*;
class yu
{
    public int findkey(int a,int b,int c)
    {
        //
        int key = Math.min(a/1000,Math.min(b/1000,c/1000));
        key *= 1000;
        a = a%1000;
        b = b%1000;
        c = c%1000;

        key = key + Math.min(a/100,Math.min(b/100,c/100))*100;
        a = a%100;
        b = b%100;
        c = c%100;
        key += Math.min(a/10,Math.min(b/10,c/10))*10;
        key += Math.min(a%10,Math.min(b%10,c%10));
        return key;
    }


    public static void main(String[] args) {
        yu s = new yu();
        Scanner sc = new Scanner(System.in);
        int a  = sc.nextInt();
        int b  = sc.nextInt();
        int c = sc.nextInt();

        System.out.println(s.findkey(a,b,c));
    }
}
/*
3521 2452 1352
*/