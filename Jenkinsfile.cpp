pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Starting Build Stage'
                sh 'g++ main/hello.cpp -o hello'  // Introduced error: wrong path
                echo 'Build Stage Successful'
            }
        }

        stage('Test') {
            steps {
                echo 'Running Tests'
                sh './hello'
                echo 'Test Stage Successful'
                sh 'exit 1'  // Intentional error to fail the stage
            }
            post {
                always {
                    echo 'Test execution completed'
                }
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying Application'
                sh 'echo Deploying hello.cpp output'
                echo 'Deployment Successful'
            }
        }
    }

    post {
        success {
            echo 'Pipeline completed successfully!'
        }
        failure {
            echo 'Pipeline failed!'
        }
    }
}
