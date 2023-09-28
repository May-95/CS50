# Recipe Finder
#### Description:
Recipe Finder is your ultimate culinary companion, designed to simplify your cooking experience. With this app, you can effortlessly search for recipes based on ingredients and filter them by dietary requirements, dish type, meal type, and cuisine type. Whether you're an aspiring home chef or just looking for dinner inspiration, this app has got you covered.

#### Preview: 
![Recipe Finder Screenshot](view.png)

## Table of Contents

- [Features](#features)
- [Technologies Used](#technologies-used)
- [Getting Started](#getting-started)

## Features

Recipe Finder offers a variety of features to enhance your culinary journey:

1. **Ingredient-Based and Dish-Based Recipe Search:** Say goodbye to food waste! Simply enter the ingredients you have or a dish you want to make, and the app will find recipes that match your search query.

2. **Diet and Health Requirement Filters:** Easily customise your search by selecting diet or health requirements such as low-carbs, vegetarian, vegan, gluten-free, and more.

3. **Dish Type Filters:** Filter recipes based on dish types, including starter, main courses, desserts, and more.

4. **Meal Type Filters:** Choose your meal type preference, whether it's breakfast, lunch, dinner, or even snacks.

5. **Cuisine Type Filters:** Explore recipes from around the world by selecting cuisine types like Italian, Mexican, Asian, and more.

6. **Link to Detailed Recipe Information:** Access comprehensive recipe details, including ingredients, preparation steps, cooking time, and serving size by going to the recipe link.

7. **User-Friendly Interface:** Enjoy a user-friendly and responsive design powered by Bootstrap, ensuring a seamless experience on both desktop and mobile devices.

## Technologies Used

Recipe Finder harnesses the power of several technologies:

- **Python:** The backbone of the app, Python handles the server-side logic and API interactions.

- **Flask:** Flask serves as the web application framework.

- **HTML, CSS, and JavaScript:** These front-end technologies create the app's structure, style, and interactivity.

- **Jinja2:** Jinja2 templating is employed to dynamically generate HTML content based on Python data.

- **Bootstrap:** The Bootstrap framework ensures a visually appealing and responsive design for a seamless user experience.

- **Edamam's Recipe Search API:** The app sources its vast collection of recipes from Edamam's Recipe Search API, providing a rich and diverse selection of dishes.

## Getting Started

To run the Recipe Finder locally on your machine, follow these steps:

1. **Clone the Repository**

2. **Install Dependencies:** Navigate to the project directory and install the required Python dependencies.

   ```bash
   cd recipe-finder
   pip install -r requirements.txt
   ```

3. **Set Up API Key:** Sign up for an API key from Edamam's Recipe Search API and replace the placeholder with your API key and APP id in the `config.py` file.

4. **Run the App:** Launch the Flask development server.

   ```bash
   flask run
   ```

5. **Access the App:** Open your web browser and go to `http://localhost:5000` to start using the Recipe Finder.

