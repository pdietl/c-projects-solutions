/*
 * program for baseball or softball on-base percentage, by John C. Lusth, 2014
 * 
 * this program may be freely distributed and modified, as long as:
 * 
 * a) the authorship of any modifications is added
 *
 * b) the reason for modification is added
 *
 * c) the comments are updated to reflect modifications
 *
 * d) the original authorship and that of any previous modifiers is preserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

// function prototypes

static void getData(int *, int *, int *, int *, int *, int *);
static void displayData(int, int, int, int, int, int);
static double computeRating(int, int, int, int, int, int);

int main()
{
    int goals, shots, corner_kicks, assists, passes, touches;
    double rating;

    // get the statistics from the user
    // pass in addresses so getDat can set these variables
    getData(&goals, &shots, &corner_kicks, &assists, &passes, &touches);

    // compute the rating
    rating = computeRating(goals, shots, corner_kicks, assists, passes, touches);

    // display the statistics
    displayData(goals, shots, corner_kicks, assists, passes, touches);

    // display the results
    printf("\nFor these statistics, the on-base percentage is %.4f\n",
           rating);

    return 0;
}

void getData(int *goals, int *shots, int *corner_kicks, int *assists, int *passes, int *touches)
{
    printf("Enter number of goals: ");
    scanf(" %d", goals);

    printf("Enter number of shots on goal: ");
    scanf(" %d", shots);

    printf("Enter number of effective corner kicks: ");
    scanf(" %d", corner_kicks);

    printf("Enter number of assists (primary): ");
    scanf(" %d", assists);

    printf("Enter number of effective passes: ");
    scanf(" %d", passes);

    printf("Enter number of touches: ");
    scanf(" %d", touches);
}

double computeRating(int goals, int shots, int corner_kicks, int assists, int passes, int touches)
{
    return (5.0 * goals + 4.0 * shots + 3.0 * corner_kicks + 2.0 * assists + passes) / touches;
}

static void print_plural(const char *s, const char *p_string, int data)
{
    printf("%2d %s%s\n", data, s, data == 1 ? "" : p_string);
}

static void pprint(const char *s, int data)
{
    print_plural(s, "s", data);
}

static void pprint_es(const char *s, int data)
{
    print_plural(s, "es", data);
}

void displayData(int goals, int shots, int corner_kicks, int assists, int passes, int touches)
{
    putchar('\n');

    pprint("goal", goals);
    pprint("shot", shots);
    pprint("effective corner kick", corner_kicks);
    pprint("primary assists", assists);
    pprint_es("effective pass",passes);
    pprint_es("touch", touches);
}
