pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Starting Build Stage'
                sh 'ls -l'  // List files to confirm hello.cpp exists
                sh 'g++ hello.cpp -o hello || exit 1'
                echo 'Build Stage Successful'
            }
        }

        stage('Test') {
            steps {
                echo 'Running Tests'
                sh './hello'
                echo 'Test Stage Successful'
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
            echo 'Pipeline failed! Check logs for errors.'
        }
    }
}
