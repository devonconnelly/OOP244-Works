// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// Name: Devon Connelly
// Email: dconnelly@myseneca.ca
// ID: 105322218
// Date Completed: Jan 20 2023

#ifndef Movie_h
#define Movie_h

namespace sdds
{

struct Movie {
    char m_title[128];
    int m_year;
    char m_rating[6];
    int m_duration;
    char m_genres[10][11];
    float m_consumerRating;
    };

    bool loadMovies();
    bool hasGenre(const Movie* mvp, const char genre[]);
    void displayMovie(const Movie* mvp);
    void displayMoviesWithGenre(const char genre[]);

}
#endif /* Movie_h */
