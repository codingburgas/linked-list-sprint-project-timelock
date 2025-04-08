#include "pch.h"

#pragma once

void saveFavourite(const string& era, const string& title, const string& content);
void askToAddToFavourites(const string& era, INFONODE* node);
void displayFavouritesByEra(const string& era);