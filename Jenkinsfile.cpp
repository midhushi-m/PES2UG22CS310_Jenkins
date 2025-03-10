pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Starting Build Stage'
                sh 'echo Build simulation'
                echo 'Build Stage Successful'
            }
        }

        stage('Test') {
            steps {
                echo 'Running Tests'
                sh 'echo Test simulation - No mvn required'
                echo 'Test Stage Successful'
            }
            post {
                always {
                    echo 'Simulated test reports generated'
                }
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying Application'
                sh 'echo Deploy simulation'
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
