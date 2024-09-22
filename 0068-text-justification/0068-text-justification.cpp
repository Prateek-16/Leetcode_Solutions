class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justifiedText;

        for (size_t i = 0, n = words.size(); i < n;) {
            vector<string> currentLine = {words[i]}; // Words in the current line
            int currentLineWidth = words[i].length();
            ++i;
          
            // Greedily add words to the current line if they fit
            while (i < n && currentLineWidth + 1 + words[i].length() <= maxWidth) {
                currentLineWidth += 1 + words[i].length();
                currentLine.push_back(words[i++]);
            }
          
            // Handle the last line or a line with a single word
            if (i == n || currentLine.size() == 1) {
                string leftJustified = currentLine[0];
              
                // Append remaining words separated by a single space
                for (size_t j = 1; j < currentLine.size(); ++j) {
                    leftJustified += " " + currentLine[j];
                }
              
                // Add trailing spaces to make the line of maxWidth length
                string trailingSpaces = string(maxWidth - leftJustified.size(), ' ');
                justifiedText.push_back(leftJustified + trailingSpaces);
                continue;
            }
          
            // Calculate the total amount of space width to distribute among words
            int totalSpaceWidth = (maxWidth - currentLineWidth) + currentLine.size() - 1;
            int spaceBetweenWords = totalSpaceWidth / (currentLine.size() - 1);
            int additionalSpaces = totalSpaceWidth % (currentLine.size() - 1);
          
            string row; // The justified row as a string
            for (size_t j = 0; j < currentLine.size() - 1; ++j) {
                row += currentLine[j] + string(spaceBetweenWords + (j < additionalSpaces ? 1 : 0), ' ');
            }
          
            // Append the last word
            row += currentLine.back();
          
            // Add the fully justified line to the result
            justifiedText.push_back(row);
        }
      
        return justifiedText;
    }
};