import React, { useEffect } from 'react';

interface NotificationProps {
  message: string;
  type?: 'success' | 'error' | 'info';
  onClose: () => void;
}

const Notification: React.FC<NotificationProps> = ({ message, type = 'success', onClose }) => {
  useEffect(() => {
    const timer = setTimeout(() => {
      onClose();
    }, 3000);

    return () => clearTimeout(timer);
  }, [onClose]);

  const backgroundColor =
    type === 'success'
      ? 'bg-green-100 text-green-800'
      : type === 'error'
      ? 'bg-red-100 text-red-800'
      : 'bg-blue-100 text-blue-800';

  return (
    <div className={`fixed top-4 right-4 px-4 py-2 rounded-lg shadow-lg z-50 ${backgroundColor}`}>
      {message}
    </div>
  );
};

export default Notification;
