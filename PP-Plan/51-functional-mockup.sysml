package PPPlan {
    part def UserProfile {
        attribute dailyCalories;
        attribute dailyProtein;
        attribute dailyFat;
        attribute dailyCarbs;
        attribute servings;
    }
    part def DietaryRestrictions {
        attribute excludedAllergens;
        attribute excludedIngredients;
        attribute dietaryPreferences;
    }
    part def RecipeCatalog {
        part recipes;
    }
    part def MenuGenerator;
    part def AllergenValidator;
    part def NutritionCalculator;
    part def ShoppingListBuilder;
    part def WeeklyPlan;

    part def ProfileScreen {
        part nutritionGoals;
        part allergenSettings;
        part foodPreferences;
    }
    part def WeeklyMenuScreen {
        part sevenDaySchedule;
        part nutrientSummary;
        part mealReplacement;
    }
    part def ShoppingListScreen {
        part groupedIngredients;
        part quantities;
    }
    part def WebInterface {
        part profileScreen : ProfileScreen;
        part weeklyMenuScreen : WeeklyMenuScreen;
        part shoppingListScreen : ShoppingListScreen;
    }
    part def PPPlanSystem {
        part web : WebInterface;
        part profile : UserProfile;
        part restrictions : DietaryRestrictions;
        part catalog : RecipeCatalog;
        part generator : MenuGenerator;
        part validator : AllergenValidator;
        part calculator : NutritionCalculator;
        part shopping : ShoppingListBuilder;
        part plan : WeeklyPlan;
    }

    action def GenerateWeeklyPlan {
        action readProfile;
        action filterRecipes;
        action selectMeals;
        action validateAllergens;
        action calculateNutrition;
        action saveWeeklyPlan;
        action aggregateShoppingList;
        first readProfile then filterRecipes;
        first filterRecipes then selectMeals;
        first selectMeals then validateAllergens;
        first validateAllergens then calculateNutrition;
        first calculateNutrition then saveWeeklyPlan;
        first saveWeeklyPlan then aggregateShoppingList;
    }
}
