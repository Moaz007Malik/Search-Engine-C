//First, we have created header files of iostream, string (because string is used instead of int and characters) unordered_mao(for unsorted array), list(to show everything in a sorted array) and algorithm(Because I had to define some programs in algorithmic way).
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;
//Made a class Page to store the url and rank of the website.
class Page {
public:
    string url;
    int rank;
//used keyword *this* to point to variable
    Page(string url, int rank) {
        this->url = url;
        this->rank = rank;
    }
};

class SearchEngine {
private:
    unordered_map<string, list<Page>> index;

public:
    void addPage(string keyword, Page page) {
        if (index.find(keyword) == index.end()) {
            list<Page> pages;
            pages.push_back(page);
            index[keyword] = pages;
        } else {
            index[keyword].push_back(page);
        }
    }

    list<Page> search(string keyword) {
        if (index.find(keyword) == index.end()) {
            return list<Page>();
        } else {
            return index[keyword];
        }
    }

    void sortPages(list<Page>& pages) {
        pages.sort([](Page a, Page b) {
            return a.rank > b.rank;
        });
    }
};

int main() {
    SearchEngine searchEngine;
    cout<<"============================================================="<<endl;
    cout<<"============================================================="<<endl;
	cout<<"\t\t\tGoogle Clone\t\t\t"<<endl;
	cout<<"============================================================="<<endl;
	cout<<"============================================================="<<endl;
    // Add some sample pages to the search engine
    
    searchEngine.addPage("Apple", Page("Apple\n\nhttps://www.apple.com",4));
    searchEngine.addPage("Apple", Page("Apple Logo\n\nhttps://www.apple-logo.com",3));
    searchEngine.addPage("Iphone", Page("Iphone-Apple\n\nhttps://www.apple.com/iphone", 1));
	
    // Search for pages containing the keyword "apple"
    string keyword;
    cout<<"Here in service...\nWhat do you want to search:\n\n";
    cin>>keyword;
    list<Page> pages = searchEngine.search(keyword);

    // Sort the pages by rank
    searchEngine.sortPages(pages);

    // Print the sorted pages
    cout << "Search results for keyword \"" << keyword << "\":\n\n" << endl;
    for (Page page : pages) {
        cout << page.url << " (rank: " << page.rank << ")" << endl;
    }

    return 0;
}
