// ///////////////////////
// RPSLV.h
// ///////////////////////

#ifndef RPSLV_H
#define RPSLV_H

#include<iostream>
#include<ctime>
#include<string>
#include<random>
#include<ctype.h>
#include<chrono>
#include<thread>
#include<stdio.h>

int storeChoice();

int generateChoice();

int compareChoices(int a, int b);

void printStandings(int wins, int losses, int draws, int total, int result);

void printResult(int a, int b, int result);

void printRules();

std::string convertName(int a);

#endif