install.packages("ggplot2")
library(ggplot2)
data("msleep")
#histogram
ggplot(msleep,aes(sleep_total)) + 
  geom_histogram(binwidth = 1,fill="orange",color="purple")

#bar_chart
ggplot(msleep,aes(vore)) + 
  geom_bar(fill="skyblue",color="red")
#structure
str(msleep)
data("mtcars")

#scatter plots
ggplot(mtcars,aes(wt,mpg,col=as.factor(cyl))) + 
  geom_point(size=5)

#boxplot
ggplot(mtcars, aes(as.factor(cyl),mpg)) + 
  geom_boxplot()
#trying splitting and row binding:
data("iris")
iris_species<-split(iris,iris$Species)
iris_setosa<-iris_species[[1]]
iris_versicolor<-iris_species[[2]]
iris_virginica<-iris_species[[3]]
head(iris_setosa)
head(iris_versicolor)
head(iris_virginica)
species_back<-rbind.data.frame(iris_setosa,iris_versicolor,iris_virginica)

#dplyr to check dataframes are equal or not
install.packages("dplyr")
library(dplyr)
all.equal(iris,species_back)

#line plot
ggplot(iris, aes(Sepal.Length,Sepal.Width,color="red")) + 
  geom_line()

#pie plot
x <- c(50,50,50)
labels <- c("Setosa","Virginica","Versicolor")
pie(x, labels, main = "Iris species count", col = rainbow(length(x)))

#importing csv
std1<-read.csv("https://raw.githubusercontent.com/ShapeLab/ZooidsCompositePhysicalizations/master/Zooid_Vis/bin/data/student-dataset.csv")
str(std1)
#deleting a column.
std1 <- subset(std1, select = -c(ethnic.group) )
#using tapply to find mean scores of every nationality.
print("mean math scores for students from different countries:") 
tapply(std1$math.grade, std1$nationality, mean)
print("mean sciences scores for students from different countries:") 
tapply(std1$sciences.grade, std1$nationality, mean)
print("mean language scores for students from different countries:") 
tapply(std1$language.grade, std1$nationality, mean)
print("mean english scores for students from different countries:") 
tapply(std1$english.grade, std1$nationality, mean)

#importing 2nd csv
std2<-read.csv("https://raw.githubusercontent.com/srpayd/R-Analysis/master/StudentsPerformance.csv")
#spliting to get only 307 rows
std2<-std2[0:307,0:7]
#adding new column
std2$id<-c(0:306)
#renaming a column
std2 <- std2 %>% 
  rename("listening.scores"="math.score")
#deleting a column
std2<-subset(std2,select=-c(gender))

#using merge to combine by id
std_combined<-merge(std1,std2,by="id")

#bar plot with colors.
ggplot(std_combined,aes(race.ethnicity,fill = race.ethnicity)) + 
  geom_bar()

head(std_combined)
