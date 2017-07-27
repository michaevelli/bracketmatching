## Bracket Matching

Takes string from standard input and alerts user if brackets are not matched.  
Will mark the location of the first unmatched bracket (if applicable).  
Will provide the missing closing brackets (if applicable).  
Brackets that will be matched are `( )` `[ ]` `{ }`.  
Due to  `<` and `>` usage as greater than or less than, they are not bracket matched

## Usage

<pre>
$ <b>gcc bracketmatching.c stack.c -o bracketmatching</b>
$ <b>./bracketmatching</b>
Enter line:
<b>><(((*></b>
missing brackets at the end of string. need: ) ) )
</pre>
<pre>
$ <b>gcc bracketmatching.c stack.c -o bracketmatching</b>
$ <b>./bracketmatching</b>
Enter line:
<b>(how (much )wood [can )a ]wood )chuck</b>
                      ^ bracket does not match here
</pre>
$ <b>gcc bracketmatching.c stack.c -o bracketmatching</b>
$ <b>./bracketmatching</b>
Enter line:
<b>([]))[]])</b>
missing brackets at the beginning of string. need: ( [
<pre>
</pre>
<pre>
$ <b>gcc bracketmatching.c stack.c -o bracketmatching</b>
$ <b>./bracketmatching</b>
Enter line:
<b>{"colorsArray": [{"red": "#f00", "green": "#0f0", "blue": "#00f", "cyan": "#0ff", "magenta": "#f0f", "yellow": "#ff0", "black": "#000"}]}</b>
brackets are matched
</pre>

## Installation

Compile with `gcc bracketmatching.c stack.c -o bracketmatching`

## Contributing

Do as you wish, I suppose

## License

MIT