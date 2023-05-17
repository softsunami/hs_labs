#ifndef LAB6_SUBSTRING_H
#define LAB6_SUBSTRING_H

#include <iostream>
#include <vector>

std::vector<int> SearchBoyerMoore(const std::string& haystack,
                                  const std::string& needle);

std::vector<int> SearchRabinKarp(const std::string& haystack,
                                 const std::string& needle);

std::vector<int> SearchKnuthMorrisPratt(const std::string& haystack,
                                        const std::string& needle);

#endif  // LAB6_SUBSTRING_H