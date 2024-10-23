### Purpose

This pull request aims to improve the overall readability of the project by enhancing variable and function names, modularizing some functions, and ensuring that the code follows clean code principles.

### Changes

<details>
  <summary>local variables</summary>
  
- l, a → removed: The intermediate variables l and a were removed, and the data is now directly appended to all_news_data using extend, simplifying the logic.
- p → page: Renamed in pagination logic to clarify that it refers to the page number.
- p2 → request_params: Renamed p2 to request_params for clearer understanding of the variable’s purpose, improving code readability.
- ai → ai_response: Makes it clear that the variable holds the response from the AI model.
- title → article_title or detailed_title: Clarifying the variable’s content.
- result → summary_result: Describes that the result is a summary.
- n → username: Updated to a more meaningful variable name to clarify that the function parameter is the user’s username, adhering to clean code principles.
- OuO → user: In the check_user_password_is_correct function, to clarify that this refers to a User object.
- n → article: Renamed in local variable to indicates the item in each iteration.
- cnt → upvoted_count, id → article_id: Standardized for clarity in upvote and news article-related functions.
- m → relevance_check_prompt, summary_prompt, summary_generation_prompt: Consolidated renaming of the prompt variable used for chat interactions with GPT, based on its role in relevance checking and summary generation.
- p2 → request_params: Changed in the function where API request parameters are built for fetching news data.


</details>


<details>
  <summary>global variables</summary>


- Replaced hard-coded magic numbers like 50, 200 with clearly defined constants (MaxUsernameSize, MaxPasswordSize) for better maintainability.
- bgs → scheduler: Renamed the background scheduler for better readability and clarity of its purpose.

</details>

<details>
  <summary>params</summary>

- u → user: Used in the functions where user information is being passed, such as in read_user_news, upvote_article, news_summary.
- id → article_id: Updated to indicate that the variable holds the ID of a news article, used in query parameters for links.
- id2 → article_id: Replaced with article_id to maintain consistency and clarity in identifying that the variable represents the article’s ID in functions like news_exists.
- p1 → plain_password, p2 → hashed_password: Clarified the parameter in the password verification function to specify that it refers to the plain-text password and hashed_password.
- n_id, u_id → article_id, user_id: Standardized the use of article_id, user_id for consistency in function like toggle_upvote.

</details>


<details>
  <summary>functions</summary>


- get_new_info → fetch_news_articles_by_keyword: Changed to clarify that the function fetches news articles based on a search term.
- get_new → fetch_and_process_news: Modified to better describe that the function fetches and processes the news articles.
- add_new → add_news_article: Clarified the purpose of adding a new news article to the database.
- toggle_upvote → toggle_article_upvote: Updated to make it clear that the function specifically handles the upvote status for a news article.
- read_news, read_user_news → fetch_news_with_upvote_details, get_user_specific_news: These two functions were renamed because their purposes were too similar, violating clean code principles. By renaming them, it clarifies that one function fetches general news with upvote details, while the other focuses on user-specific news, making their roles distinct.
- verify → verify_password: Renamed the function for clarity, making it more descriptive, ensures the function name clearly conveys its purpose.
- check_user_password_is_correct → validate_user_credentials: Renamed the function to better reflect its purpose of both querying the user from the database and validating the user’s credentials (username and password), which aligns more closely with clean code principles.

</details>
