# ───────────────────────────────────────────────────────
# Mini-Project: Air Quality & Diamond Price Exploration
# ───────────────────────────────────────────────────────

if(!require(ggplot2))    install.packages("ggplot2")
if(!require(dplyr))      install.packages("dplyr")
if(!require(tidyr))      install.packages("tidyr")
if(!require(scales))     install.packages("scales")
library(ggplot2)
library(dplyr)
library(tidyr)
library(scales)

# 2. Dataset 1: airquality ---------------------------------------------------

# a) Inspect structure & head
data("airquality")
str(airquality)
head(airquality)

# b) Clean: remove rows with missing Ozone or Solar.R
aq <- airquality %>%
  drop_na(Ozone, Solar.R)

# c) Histogram of Ozone levels
ggplot(aq, aes(x = Ozone)) +
  geom_histogram(binwidth = 10, fill = "steelblue", color = "white") +
  labs(title = "Histogram of Ozone (ppb)",
       x = "Ozone (ppb)", y = "Count")

# d) Scatter: Solar.R vs Ozone, colored by Month
ggplot(aq, aes(x = Solar.R, y = Ozone, color = factor(Month))) +
  geom_point(size = 3, alpha = 0.7) +
  scale_color_discrete(name = "Month") +
  labs(title = "Ozone vs Solar Radiation by Month",
       x = "Solar Radiation (Langley)", y = "Ozone (ppb)")

# e) Line plot: Daily average Temperature by Month
aq %>%
  group_by(Month, Day) %>%
  summarize(avgTemp = mean(Temp)) %>%
  ggplot(aes(x = Day, y = avgTemp, group = Month, color = factor(Month))) +
    geom_line(size = 1) +
    scale_color_brewer(palette = "Dark2", name = "Month") +
    labs(title = "Daily Avg Temperature in New York, 1973",
         x = "Day of Month", y = "Avg Temp (°F)")

# f) Boxplot: Distribution of Wind speeds across Months
ggplot(aq, aes(x = factor(Month), y = Wind)) +
  geom_boxplot(fill = "lightgreen", color = "darkgreen") +
  labs(title = "Wind Speed by Month",
       x = "Month", y = "Wind (mph)")

# g) Heatmap: Ozone across Days and Months
aq_wide <- aq %>%
  select(Month, Day, Ozone) %>%
  pivot_wider(names_from = Day, values_from = Ozone)

# Convert back to long for ggplot
aq_long <- aq_wide %>%
  pivot_longer(-Month, names_to = "Day", values_to = "Ozone") %>%
  mutate(Day = as.integer(Day))

ggplot(aq_long, aes(x = Day, y = factor(Month), fill = Ozone)) +
  geom_tile(color = "white") +
  scale_fill_viridis_c(na.value = "grey90") +
  labs(title = "Heatmap of Ozone Levels",
       x = "Day", y = "Month", fill = "Ozone (ppb)")

# 3. Dataset 2: diamonds 

# a) Inspect
data("diamonds")
str(diamonds)
head(diamonds)

# b) Scatter: Carat vs Price, with smooth trend
ggplot(diamonds, aes(x = carat, y = price)) +
  geom_point(alpha = 0.1) +
  geom_smooth(method = "loess", se = FALSE, color = "red") +
  labs(title = "Diamond Price vs Carat Weight",
       x = "Carat", y = "Price (USD)")

# c) Density plot: Distribution of Price by Cut
ggplot(diamonds, aes(x = price, fill = cut)) +
  geom_density(alpha = 0.5) +
  labs(title = "Density of Diamond Prices by Cut",
       x = "Price (USD)", y = "Density")

# d) Violin + jitter: Price distribution across Color grades
ggplot(diamonds, aes(x = color, y = price)) +
  geom_violin(fill = "lightblue") +
  geom_jitter(width = 0.2, alpha = 0.1) +
  labs(title = "Violin Plot of Price by Color",
       x = "Color Grade", y = "Price (USD)")

# e) Bar chart: Count of diamonds per clarity grade
ggplot(diamonds, aes(x = clarity)) +
  geom_bar(fill = "orange", color = "black") +
  labs(title = "Count of Diamonds by Clarity",
       x = "Clarity Grade", y = "Count")

# f) Facet: Price vs Carat, faceted by Cut
ggplot(diamonds, aes(x = carat, y = price)) +
  geom_point(alpha = 0.05) +
  facet_wrap(~ cut) +
  labs(title = "Price vs Carat Faceted by Cut",
       x = "Carat", y = "Price (USD)")

diam_summary <- diamonds %>%
  group_by(cut, color) %>%
  summarize(mean_price = mean(price), .groups = "drop")

print(diam_summary)

write.csv(diam_summary, "diamond_price_summary.csv", row.names = FALSE)
