#ifndef GLOBAL_H
#define GLOBAL_H

#include <QRegExp>
#include <QString>


/*
Copy in NotePad++. To remove the spaces and cr :
Replace: \r\n           with nothing
Replace: single space   with nothing

^
(
    (
        (
            ([aA][0-8]) |
            ([bB][0-4]) |
            ([cdCD][0-2])
        )+;
        |
        (
            \\+
        |
            \\-
        )+;?
        |
        ((
            \\\\27
        );?)?
        |
        ((
            \\?
        );?)?
    )+
    |
    ^clear$
)
$

*/

#define REGEX_SEQUENCE      "^(((([aA][0-8])|([bB][0-4])|([cdCD][0-2]))+;|(\\+|\\-)+;?|((\\\\27);?)?|((\\?);?)?)+|^clear$)$"

// 1-9999
#define REGEX_SEQUENCEDELAY "^[1-9][0-9]{0,3}$"

// COM0 - COM99
#define REGEX_PORT          "^COM[0-9]{1,2}$"

// true / false (not case sensitive)
#define REGEX_BOOL          "^(([tT][rR][uU][eE])|([fF][aA][lL][sS][eE]))$"

namespace Regex
{
    inline bool isValid( const QString& regex, const QString& str )
    {
        if( (str.size() > 0 && QRegExp( regex ).indexIn( str ) == -1) || str.size() == 0 )
            return false;
        return true;
    }
}

#endif // GLOBAL_H
