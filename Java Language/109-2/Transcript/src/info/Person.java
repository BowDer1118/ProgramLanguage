package info;

public class Person {
    private String firstName;
    private String lastName;
    private City city;
    private String birthday;
    private Gender gender;

    public Person(String firstName, String lastName, City city, String birthday, Gender gender) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.city=city;
        this.birthday = birthday;
        this.gender = gender;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public City getCity() {
        return city;
    }

    public String getBirthday() {
        return birthday;
    }

    public Gender getGender() {
        return gender;
    }

    @Override
    public String toString() {
        return  "firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", city=" + city +
                ", birthday='" + birthday + '\'' +
                ", gender=" + gender +
                '}';
    }
}

