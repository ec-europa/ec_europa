@api
Feature: Pager functionality
  In order to show functionality added by the Pager
  As an authenticated user with admin role
  I need to see the Next, Previous, ellips and other links in between

  Scenario: Pager behaves correctly with a high number of pages.
    Given "500" nodes of type "article"

    When I visit "/node"
    Then I should see the link "Next ›"
    Then I should not see the link "‹ Previous"
    Then I should see "Page 1 2 3 4 5 6 7 8 9 … Page 50 Next ›" in the "pager" region
#
   When I click "Next ›"
   Then I should see "‹ Previous 1 Page 2 3 4 5 6 7 8 9 … Page 50 Next ›" in the "pager"
   When I click "Next ›"
   Then I should see "‹ Previous 1 2 Page 3 4 5 6 7 8 9 … Page 50 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous 1 2 3 Page 4 5 6 7 8 9 … Page 50 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous 1 2 3 4 Page 5 6 7 8 9 … Page 50 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous Page 1 2 3 4 5 Page 6 7 8 9 10 … Page 50 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous Page 1 … 3 4 5 6 Page 7 8 9 10 11 … Page 50 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous Page 1 … 4 5 6 7 Page 8 9 10 11 12 … Page 50 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous Page 1 … 5 6 7 8 Page 9 10 11 12 13 … Page 50 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous Page 1 … 6 7 8 9 Page 10 11 12 13 14 … Page 50 Next ›" in the "pager"
#
   And I click "50"
   Then I should see "‹ Previous Page 1 … 46 47 48 49 Page 50" in the "pager"
   And I should not see the link "Next ›"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 45 46 47 48 Page 49 50" in the "pager"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 44 45 46 47 Page 48 49 50" in the "pager"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 43 44 45 46 Page 47 48 49 50" in the "pager"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 42 43 44 45 Page 46 47 48 49 50" in the "pager"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 41 42 43 44 Page 45 46 47 48 49" in the "pager"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 40 41 42 43 Page 44 45 46 47 48 … Page 50 Next ›" in the "pager"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 39 40 41 42 Page 43 44 45 46 47 … Page 50 Next ›" in the "pager"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 38 39 40 41 Page 42 43 44 45 46 … Page 50 Next ›" in the "pager"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 37 38 39 40 Page 41 42 43 44 45 … Page 50 Next ›" in the "pager"
#
   When I click "‹ Previous"
   Then I should see "‹ Previous Page 1 … 36 37 38 39 Page 40 41 42 43 44 … Page 50 Next ›" in the "pager"
#
 Scenario: Pager behaves correctly with less pages than pagination quantity (set to 9).
   Given "60" nodes of type "article"
#
   When I visit "/node"
   Then I should see "Page 1 2 3 4 5 6 Next ›" in the "pager"
   And I should not see the link "‹ Previous"
#
   When I click "Next ›"
   Then I should see "‹ Previous 1 Page 2 3 4 5 6 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous 1 2 Page 3 4 5 6 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous 1 2 3 Page 4 5 6 Next ›" in the "pager"
#
   When I click "Next ›"
   Then I should see "‹ Previous 1 2 3 4 Page 5 6 Next ›" in the "pager"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 2 3 4 5 Page 6" in the "pager"
    And I should not see the link "Next ›"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 2 3 4 Page 5 6 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 2 3 Page 4 5 6 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 2 Page 3 4 5 6 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 Page 2 3 4 5 6 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "Page 1 2 3 4 5 6 Next ›" in the "pager"
    And I should not see the link "‹ Previous"

  Scenario: Pager behaves correctly with less pages than pagination quantity (set to 9).
    Given "30" nodes of type "article"

    When I visit "/node"
    Then I should see "Page 1 2 3 Next ›" in the "pager"
    And I should not see the link "‹ Previous"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 Page 2 3 Next ›" in the "pager"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 2 Page 3" in the "pager"
    And I should not see the link "Next ›"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 Page 2 3 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "Page 1 2 3 Next ›" in the "pager"
    And I should not see the link "‹ Previous"

  Scenario: Pager behaves correctly with no pages.
    Given "5" nodes of type "article"
    When I visit "/node"
    Then I should not see ".ecl-pager"

  Scenario: Pager behaves correctly with the exact number of "quantity" pages (set to 90).
    Given "90" nodes of type "article"
    When I visit "/node"

    Then I should see "Page 1 2 3 4 5 6 7 8 9 Next ›" in the "pager"
    And I should not see the link "‹ Previous"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 Page 2 3 4 5 6 7 8 9 Next ›" in the "pager"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 2 Page 3 4 5 6 7 8 9 Next ›" in the "pager"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 2 3 Page 4 5 6 7 8 9 Next ›" in the "pager"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 2 3 4 Page 5 6 7 8 9 Next ›" in the "pager"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 2 3 4 5 Page 6 7 8 9 Next ›" in the "pager"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 2 3 4 5 6 Page 7 8 9 Next ›" in the "pager"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 2 3 4 5 6 7 Page 8 9 Next ›" in the "pager"
#
    When I click "Next ›"
    Then I should see "‹ Previous 1 2 3 4 5 6 7 8 Page 9" in the "pager"
    And I should not see the link "Next ›"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 2 3 4 5 6 7 Page 8 9 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 2 3 4 5 6 Page 7 8 9 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 2 3 4 5 Page 6 7 8 9 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 2 3 4 Page 5 6 7 8 9 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 2 3 Page 4 5 6 7 8 9 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 2 Page 3 4 5 6 7 8 9 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "‹ Previous 1 Page 2 3 4 5 6 7 8 9 Next ›" in the "pager"
#
    When I click "‹ Previous"
    Then I should see "Page 1 2 3 4 5 6 7 8 9 Next ›" in the "pager"
    And I should not see the link "‹ Previous"
