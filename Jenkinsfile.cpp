pipeline {
    agent any

    stages {
        stage('Clone Repository') {
            steps {
                // Clone the repository
                git branch: 'main', url: 'https://github.com/midhushi-m/PES2UG22CS310_Jenkins.git'
            }
        }

        stage('Build') {
            steps {
                // Compile the C++ code
                build 'PES2UG22CS310-1'
                sh 'g++ main.cpp -o output'
            }
        }

        stage('Test') {
            steps {
                // Run the output file
                sh './output'
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying...'
            }
        }
    }

    post {
        failure {
            error('Pipeline failed')
        }
    }
}
