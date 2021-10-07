#!/usr/bin/python3
"""Recursively query the Reddit API & print a sorted count of hot articles by
given keywords. Case-insensitive, space delimited."""
import requests


def count_words(subreddit, word_list, after=None, count={}):
    """Counts hot articles by keyword(s) for a given subreddit."""
    if after is None:
        subURL = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    else:
        subURL = 'https://www.reddit.com/r/{}/hot.json?after={}'.format(
            subreddit, after)
    subREQ = requests.get(subURL,
                          headers={"user-agent": "user"},
                          allow_redirects=False)
    try:
        data = subREQ.json().get("data")
    except:
        return
    for word in word_list:
        word = word.lower()
        if word not in count.keys():
            count[word] = 0
    children = data.get("children")
    for child in children:
        title = (child.get("data").get("title").lower())
        title = title.split(' ')
        for word in word_list:
            word = word.lower()
            count[word] += title.count(word)
    after = data.get("after")
    if after is not None:
        return count_words(subreddit, word_list, after, count)
    else:
        sorted_subs = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for i in sorted_subs:
            if i[1] != 0:
                print(i[0] + ": " + str(i[1]))
